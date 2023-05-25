#include "seller.h"

Seller::Seller(string command){
    vector<string> names = {"A1", "A2", "A3", "A4", "A5", "A6"};
    vector<int> vals = {2, 3, 4, 5, 6, 8, 6};
    vector<int> moneyUnits = {1,2,5,10};
    
    //初始化商品数目
    int i = 0,it = 0;
    int sum = 0;
    for (;i<command.size();i++) {
        char cur = command[i];
        if (cur == '-' || cur == ' ') {
            if (sum > 30) throw new SellerException(2);
            Commodity comm(names[it], vals[it], sum);
            commodities[names[it]] = comm;
            totalCount += sum;sum = 0;it++;
            if(cur == ' ') break;
        } else {
            sum = sum * 10 + cur - '0';
        }
    }

    //初始化余额数目
    it = 0;
    sum = 0;
    for (i++;i<command.size();i++) {
        char cur = command[i];
        if (cur == '-' || cur == ';') {
            if (sum > 30) throw new SellerException(2);
            save[moneyUnits[it]] = sum;            
            sum = 0;it++;
            if(cur == ';') break;
        } else {
            sum = sum * 10 + cur - '0';
        }
    }

    cout<<"==== Init Seller Success ===="<<endl;
}

void Seller::analyze(string command){
    switch (command[0])
    {
    case 'r':
        Seller(command.substr(3));
        break;
    case 'p':
        break;
    case 'b':
        //购买
        break;
    case 'c':
        //退币
        break;
    case 'q':
        //查询
        break;
    default:
        throw new SellerException(1);
        break;
    }
}

void Seller::refund(){
    if(moneyDrop == 0){
        throw new SellerException(7);
    }
    vector<int> units = {10,5,2,1};
    int it = 0;
    while(moneyDrop != 0){
        if(save[units[it]] != 0 && moneyDrop>=units[it]){
            moneyDrop -= units[it];
            save[units[it]]--;
        } else {
            it++;
        }
    }
}

void Seller::fund(int money){
    if(money != 1 && money != 1 && money != 5 && money != 10){
        throw new SellerException(8);
    } else if(save[1]+save[2]*2<money){
        throw new SellerException(6);
    } else if(totalCount == 0){
        throw new SellerException(4);
    }
    moneyDrop += money;
    save[money]++;
    cout<<"====== Drop Money Success ======="<<endl;
}

void Seller::purchase(string name,int count){
    if(commodities.find(name) == commodities.end()){
        throw new SellerException(2);
    } else if (commodities[name].count<count){
        throw new SellerException(4);
    } else if(moneyDrop < commodities[name].price*count){
        throw new SellerException(5);
    } else{
        commodities[name].count -= count;
        totalCount -= count;
        moneyDrop -= commodities[name].price*count;
    }
}

void Seller::ShowMenu(){
    cout<<"=============== Menu ==============="<<endl;
    for(auto com:commodities){
        cout<<"=="<<com.second.name<<"/t"<<com.second.price<<"/t"<<com.second.count<<"=="<<endl;
    }
    cout<<"===================================="<<endl;
}

void Seller::showDetail(string comm_name){
    if(commodities.find(comm_name) == commodities.end()){
        throw new SellerException(2);
    }
    cout<<"== Detail of commodity named \""<<comm_name<<"\" =="<<endl;
    cout<<"=="<<commodities[comm_name].name<<"/t"<<commodities[comm_name].price<<"/t"<<commodities[comm_name].count<<"=="<<endl;
    cout<<"==================================================="<<endl;
}