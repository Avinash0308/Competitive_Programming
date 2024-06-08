#include<bits/stdc++.h>
using namespace std;

class EngineerFirm{
    vector<int> income;
    public:
    EngineerFirm(int n){
        income.resize(n,0);
    }
    void assignSalaries(vector<int> salaries){
        int n = salaries.size();
        for(int i = 0; i<n && i<income.size(); i++){
            income[i] = salaries[i];
        }
        cout<<"Incomes of engineers credited"<<endl;
    }
    void averageSalary(){
        int total = 0;
        for(int i = 0; i<income.size();i ++){
            total += income[i];
        }
        int x = income.size();
        float avg = (float)total/x;
        cout<<"Average Salary of engineers is "<<avg<<endl;
    }
    void maxSalary(){
        int maxy = 0;
        for(int i = 0; i<income.size(); i++){
            maxy = max(maxy,income[i]);
        }
        cout<<"Maximum salary amongst engineers is "<<maxy<<endl;
    }
    void minSalary(){
        int miny = 0;
        for(int i = 0; i<income.size(); i++){
            miny = min(miny,income[i]);
        }
        cout<<"Minimum salary amongst engineers is "<<miny<<endl;
    }
};

class AccountantFirm{
    vector<int> income;
    public:
    AccountantFirm(int n){
        income.resize(n,0); 
    }
    void assignSalaries(vector<int> salaries){
        int n = salaries.size();
        for(int i = 0; i<n && i<income.size(); i++){
            income[i] = salaries[i];
        }
        cout<<"Income of accountants credited"<<endl;
    }
    void averageSalary(){
        int total = 0;
        for(int i = 0; i<income.size();i ++){
            total += income[i];
        }
        int x = income.size();
        float avg = (float)total/x;
        cout<<"Average salary of accountant is "<<avg<<endl;
    }
    void maxSalary(){
        int maxy = 0;
        for(int i = 0; i<income.size(); i++){
            maxy = max(maxy,income[i]);
        }
        cout<<"Maximum salary amongst accountants is "<<maxy<<endl;
    }
    void minSalary(){
        int miny = 0;
        for(int i = 0; i<income.size(); i++){
            miny = min(miny,income[i]);
        }
        cout<<"Minimum salary amongst accountants is "<<miny<<endl;
    }
};

int main(){
    return 0;
}