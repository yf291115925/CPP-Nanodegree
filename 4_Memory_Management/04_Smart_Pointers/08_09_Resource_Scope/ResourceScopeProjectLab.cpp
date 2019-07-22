/*
In our project we are using static global initialization in a section dedicated
to our declaration of first attribute. This attribute is used to invoke
registration of atexit function, which is in charge to call its input parameter
function upon exit from the main function. We are calling shutdown function
which is in charge of deleting of counts of references to all stored memory
addresses and simply deleting any remaining used space in memory. For this we
need to set our first flag just once in global scope and reset it after first
initialization by class constructor. Also we need to declare our static
container in global scope.
*/

// STATIC INITIALIZATION
// Creates storage for the static variables
template <class T, int size>
std::list<PtrDetails<T>> Pointer<T, size>::refContainer;
template <class T, int size>
bool Pointer<T, size>::first = true;

namespace __Tester__ {
  typedef unsigned long ULong;

  struct Info {
    void *address;
    long line;
    std::size_t _size;
    bool isArray;
    Info *link;
  } * alloc_map(0);

  int alloc_count(0), dealloc_count(0);
  long alloc_total(0), dealloc_total(0), alloc_current(0), alloc_max(0);
  bool notifications(false);
  char previous_name[1000] = "";
  FILE *output(stdout);

  void redirect_output(const char name[]) {
    if (output != stdout) fclose(output);
    if (name) {
      if (strcmp(name, previous_name))
        output = fopen(name, "w");
      else
        output = fopen(name, "a");
      if (output) {
        strcpy(previous_name, name);
        return;
      }
    }
    output = stdout;
  }

  void *Alloc(long line, std::size_t _size, bool isArray) {
    void *address(std::malloc(_size));
    if (!address) throw std::bad_alloc();
    if (line != -1) {
      alloc_count++;
      alloc_total += _size;
      alloc_current += _size;
      if (alloc_current > alloc_max) alloc_max = alloc_current;
      if (notifications) {
        if (line == -2)
          std::fprintf(output, ">>> Internally allocated ");
        else
          std::fprintf(output,
                      ">>> in %ld. line of the script we have allocated memory "
                      "with the line: ",
                      line);
        std::fprintf(output, "%lu bytes, on address %p\n", (ULong)_size, address);
      }
    }
    Info info = {address, line, _size, isArray, alloc_map};
    if (!(alloc_map = (Info *)std::malloc(sizeof(Info)))) throw std::bad_alloc();
    *alloc_map = info;
    return address;
  }
  void Dealloc(void *ptr, bool isArray) {
    Info *current(alloc_map), *previous(0);
    for (; current && current->address != ptr; current = current->link)
      previous = current;
    if (current) {
      if (current->line != -1) {
        std::size_t _size(current->_size);
        dealloc_count++;
        dealloc_total += _size;
        alloc_current -= _size;
        if (notifications) {
          std::fprintf(output, ">>> Releasing %lu bytes on address %p\n",
                      (ULong)_size, ptr);
        }
        if (isArray != current->isArray)
          std::fprintf(output,
                      "*** ERROR: Releasing on address %p %s "
                      "should be done with delete[]!\n",
                      ptr, isArray ? "no" : "yes");
      }
      if (previous)
        previous->link = current->link;
      else
        alloc_map = current->link;
      std::free(current);
      std::free(ptr);
    } else if (ptr) {
      const std::size_t pomak(sizeof(std::size_t));
      void *ptr1((char *)ptr + (isArray ? pomak : -pomak));
      for (current = alloc_map; current && current->address != ptr1;
          current = current->link)
        ;
      if (current)
        std::fprintf(output,
                    "*** ERROR: Releasing on address %p %s should "
                    "be done with delete[]!\n",
                    ptr1, isArray ? "no" : "yes");
      else
        fprintf(output,
                "*** ERROR: You are trying to release already released space "
                "on address %p!\n",
                ptr);
    }
  }
  void Terminator();
  struct Reporter {
    void (*old_terminator)();
    Reporter() : old_terminator(std::set_terminate(Terminator)) {}
    ~Reporter() {
      std::fprintf(
          output,
          "\n\n+---------------+\n| FINAL REPORT: |\n"
          "+---------------+\n\nTotal number of allocations: %d\nTotal number of "
          "deallocations: %d\nTotal number of allocations in bytes: %ld\n"
          "Total number of deallocations in bytes: %ld\nMaximum "
          "memory occupation during runtime in bytes: %ld\nMemory occupation "
          "upon completion: %ld\n",
          alloc_count, dealloc_count, alloc_total, dealloc_total, alloc_max,
          alloc_current);
      if (alloc_map) {
        std::fprintf(output,
                    "\n\nLEAK! YOU HAVE MEMORY LEAKAGE ON FOLLOWING PLACES: \n");
        for (Info *current = alloc_map; current; current = current->link)
          if (current->line == -2)
            std::fprintf(output,
                        " - address %p, %lu bytes, allocated internally\n",
                        current->address, (ULong)current->_size);
          else
            std::fprintf(output,
                        " - address %p, %lu bytes, allocated in %ld. "
                        "line\n",
                        current->address, (ULong)current->_size, current->line);
        std::fprintf(output, "\n");
      } else
        std::fprintf(output, "\n\nGREAT JOB! YOU DO NOT HAVE MEMORY LEAKAGE\n\n");
      if (output != stdout) fclose(output);
      std::system("PAUSE");
    }
  } reporter;
  void Terminator() {
    reporter.Reporter::~Reporter();
    reporter.old_terminator();
  }
}  // namespace __Tester__