#ifndef SELLER_H
#define SELLER_H
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Commodity
{
public:
    Commodity(string t_name,int t_price,int t_count):name(t_name),price(t_price),count(t_count){};
    string name;
    int price;
    int count;
};

class Seller
{
public:
    Seller(string command);
    void analyze(string command);//分析命令
private:
    int moneyDrop; // 已经投入的金额
    int totalCount = 0; // 商品数目总计
    unordered_map<string,Commodity> commodities; //商品列表-名字为索引
    unordered_map<int,int> save{{1,0},{2,0},{5,0},{10,0}};//金额面值与张数
    void refund();//退币
    void fund(int money);//投币
    void purchase(string comm_name,int comm_count);//出货
    void ShowMenu();//显示    
    void showDetail(string comm_name);//查询货物细节
};

class SellerException:exception{
public:
    SellerException(int signal);
    // 1 无效指令
    // 2 初始化失败
    // 3 查询商品不存在
    // 4 商品剩余数目不足
    // 5 余额不足以购买
    // 6 零钱不足，投币失败
    // 7 存币为0，无需退币
    // 8 入币异常
};

#endif