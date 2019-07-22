#include "route_model.h"
#include <iostream>


/*
在07_The_Node_Class 裡面, 已經把RouteModel 內部成員都寫好了
現在可以來創建一個model


Create RouteModel Nodes
Now that you have a RouteModel class and you have completed the RouteModel::Node nested class, you can create RouteModel nodes.

When the RouteModel constructor is called, it calls the Model constructor with the open street map data.
When this happens, a collection of Model:Node objects are created. However,
in order to perform the A* search, you will need to use RouteModel::Node objects instead.

=> model.cpp
看code 可以發現, 當RouteModel 的建構子一被呼叫, 直接把xml 丟去創建 Model
    //constructor
    Model::Model( const std::vector<std::byte> &xml )
    {
        LoadData(xml);

        AdjustCoordinates();

        std::sort(m_Roads.begin(), m_Roads.end(), [](const auto &_1st, const auto &_2nd){
            return (int)_1st.type < (int)_2nd.type;
        });
    }

可以看到, Model 馬上去loadData, AdjustCoordinates 轉成xy座標, 把 m_Roads Sort.
(Model 中有成員: model.h
    std::vector<Node> m_Nodes; -->LoadData /osm/node 都先放進來 m_nodes, 把 category=highway 放到 m_Roads
    std::vector<Way> m_Ways;
    std::vector<Road> m_Roads; ---> sort 屬於Roads 的 Nodes
    std::vector<Railway> m_Railways;
    std::vector<Building> m_Buildings;
    std::vector<Leisure> m_Leisures;
    std::vector<Water> m_Waters;
    std::vector<Landuse> m_Landuses;)

=> //因為Model是應付直接loadData XML時裝的data, 裡面只有一個Node.x=lon, Node.y=lat 經緯度 的資訊, 要能做A*, 需要Node x,y,g,h,
因此重新在RouteModel 再包一次Nodes, 才給A*用

=>在Model 這層 m_Nodes,m_Roads ... 都已經有所有xml理的資訊了, 所有Nodes 都已經存進memory了


In this exercise, you will modify the RouteModel constructor.
The constructor will use the vector of Model:Node objects to create new RouteModel::Node objects.
These RouteModel::Node objects will then be stored in the m_Nodes vector of the RouteModel.
=>如上所說, 這次就是要我們把Model 的Nodes, 再包一層到RouteModel 的 m_Nodes 中, 準備丟給A*


*/


/*
To complete this exercise:
    1.In the RouteModel constructor in route_model.cpp, write a for loop with a counter
        to loop over the vector of Model::Nodes given by this->Nodes().
    2.For each Model node in the loop, use the RouteModel::Node constructor
        to create a new node, and push the new node to the back of m_Nodes.
    3.To do this, you should use the RouteModel::Node constructor that accepts three arguments:

    Node(int idx, RouteModel * search_model, Model::Node node)

The first argument is given by the counter index. The second argument should be a pointer to the
RouteModel instance that the Node belongs to. Since you are writing your code inside the RouteModel
constructor, you can use the this keyword to get a pointer to the current RouteModel instance.
In other words, you can pass this as the second argument.
The last argument is given by the Model::Node in the for loop.

*/

//Note:
// xml is the open street map data.
//constructor
RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml) {

/*
//因為他是用initialization list 的方式寫的, 進到這裡(Body) 時, Model 已經 initial 好了
也就是說, Model 理的Node 也都存好xml 的data 了

目的=>幫我(RouteModel)自己造 m_Nodes


1.In the RouteModel constructor in route_model.cpp, write a for loop with a counter
    to loop over the vector of Model::Nodes given by this->Nodes().
2.For each Model node in the loop, use the RouteModel::Node constructor
    to create a new node, and push the new node to the back of m_Nodes.


ps.To do this, you should use the RouteModel::Node constructor that accepts three arguments:
Node(int idx, RouteModel * search_model, Model::Node node)

*/

    //因為RouteModel 是繼承Model, 因此可以用Model 的公開資訊, m_Nodes 是Model 的private data, 但是 Nodes() 方法是 public 的
    //用this 就可以指到, auto &Nodes() const noexcept { return m_Nodes; } => Model 中的一個public method 去得到 m_Nodes的 reference
    //因為現在 RouteModel已經繼承了Model, 因此對 RouteModel 來說 Nodes()方法就是自己的public, 對自己的方法用this 無誤

    //小心, 即使用auto ,也要加&, 不如好好寫清楚
    //auto& con_m_Nodes = this->SNodes();
    std::vector<RouteModel::Node>& routemodel_m_Nodes = this->SNodes();
    const std::vector<Model::Node>& model_m_Nodes = this->Nodes();//連const type 都不能少
    //std::vector<Model::Node> model_m_Nodes = this->Nodes();//不知道為啥拿不到 reference, 明明 model.h 是return & , 先拿copy來用
    //model_m_Nodes[0].x = 99;

    std::cout<< routemodel_m_Nodes.size() << "\n";
    std::cout<< &routemodel_m_Nodes <<"\n";
    std::cout<< &this->SNodes() <<"\n";
    //std::cout<< routemodel_m_Nodes[0].g_value <<"\n";
    //std::cout<< this->SNodes()[0].g_value <<"\n";

    std::cout<< model_m_Nodes[0].x <<"\n";
    std::cout<< this->Nodes()[0].x <<"\n";
    std::cout<< &model_m_Nodes <<"\n";
    std::cout<< &this->Nodes() <<"\n";
    for (int i =0; i < model_m_Nodes.size();++i){
        //拿出Model 中已經塞好的Node
        //auto& Modelnode = this->Nodes()[i];
        Model::Node Modelnode = model_m_Nodes[i];

        //std::cout<<Modelnode.x<<"\n";
        //接著要幫RouteModel 自己建Node, 呼自己的Node constructor
        //要自己class 的 address, 就直接塞 this給它
        RouteModel::Node newnode = Node(i, this, Modelnode);
        routemodel_m_Nodes.push_back(newnode);
        //this->SNodes().push_back(newnode);

        // private 變數不能透過 宣告物件直接呼叫, 假設xxx是private ex: car1.xxx -> error
        // 但在class 內部, method, constructor 是可以直接內部操作的, 不然你怎寫method 讓別人拿這個變數
        //m_Nodes.push_back(newnode);
        //std::cout<<"size: "<<m_Nodes.size()<<"\n";

    }

    /*
    int counter=0;
    auto con_m_Nodes = this->SNodes();
    for(auto node:this->Nodes()){
        con_m_Nodes.push_back(Node(counter, this, node));
        counter++;
    }
    */



}


















//
