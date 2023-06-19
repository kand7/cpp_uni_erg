#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

using std::string;


class binaryData{
    private:
    char age[25];
    char first[25];
    char last[25];
    char phone[25];
    public:
    binaryData(){};
    ~binaryData(){};
    void setData(int age,string first,string last,string phone){
        sprintf(this->age,"%d",age);
        sprintf(this->first,"%s",first.c_str());
        sprintf(this->last,"%s",last.c_str());
        sprintf(this->phone,"%s",phone.c_str());
    }
    void save(std::fstream &f){
        f.write(age,sizeof(age));
        f.write(first,sizeof(first));
        f.write(last,sizeof(last));
        f.write(phone,sizeof(phone));

    }
    void writeBinaryFile(string file){
        std::fstream fs;
        fs.open(file,std::ios::out | std::ios::binary | std::ios::app);
        if(!fs.good()){
            std::cout << "File Error" << file << std::endl;
        }
        else{
            this->save(fs);
        }
        fs.close();
    }

    void read(string file){
        std::fstream binaryFile;
        int size = 0;
        binaryFile.open(file,std::ios::in | std::ios::binary);
        binaryFile.seekg(0,std::ios::end);
        size = (int)binaryFile.tellg();
        binaryFile.seekg(0,std::ios::beg);

        while(binaryFile.tellg() < size){
            binaryFile.read(age,sizeof(age));
            binaryFile.read(first,sizeof(first));
            binaryFile.read(last,sizeof(last));
            binaryFile.read(phone,sizeof(phone));

            std::cout << age << "\t" << first << "\t " << last << "\t" << phone << std::endl;
        }
        binaryFile.close();
    }
};

int main(){
    string first,last,phone;
    int age;
    //std::unique_ptr<binaryData> bd(new binaryData()); //for exclusive ownership 
    binaryData * bd = new binaryData(); //also works
    std::cout << "Enter Age : ";
    std::cin >> age;
    std::cout << "Enter First Name : ";
    std::cin >> first;
    std::cout << "Enter Last Name : ";
    std::cin >> last;
    std::cout << "Enter Phone Number: ";
    std::cin >> phone;
    bd->setData(age,first,last,phone);
    bd->writeBinaryFile("record.dat");
    bd->read("record.dat");
    return 0;
}
