#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void delete_line(const char *file_name, int n) 
{ 
    ifstream is(file_name); 
    ofstream ofs; 
    ofs.open("temp.txt", ofstream::out); 
    char c; 
    int line_no = 1; 
    while (is.get(c)){ 
        if (c == '\n') 
        line_no++; 
        if (line_no-1 != n) 
            ofs << c; 
    } 
    ofs.close(); 
    is.close(); 
    remove(file_name); 
    rename("temp.txt", file_name); 
} 

void delete_line2(const char *file_name, int n) 
{ 
    ifstream is(file_name); 
    ofstream ofs1, ofs2; 
    ofs1.open("temp.txt", ofstream::out); 
    ofs2.open("done.txt", ofstream::out | ofstream::app); 
    char c; 
    int line_no = 1; 
    while (is.get(c)){ 
        if (c == '\n') 
           line_no++; 
        if (line_no-1 != n) 
            ofs1 << c;
        if (line_no-1 == n) 
            ofs2 << c;
    } 
    ofs1.close(); 
    ofs2.close();
    is.close(); 
    remove(file_name); 
    rename("temp.txt", file_name); 
} 

void delete_line3() 
{  
    ifstream f_todo("todo.txt");
    ifstream f_done("done.txt"); 
    string line1, line2;
    int l1 = 0;
    int l2 = 0; 
    while (getline(f_todo, line1)){ 
           l1++;
    }
    while (getline(f_done, line2)){ 
           l2++;
    } 
    f_todo.close(); 
    f_done.close();
    cout<<endl<<"completed: "<<l2<<" to-do: "<<l1<<endl;
} 


int main(int argc, char* argv[])
{
    int n;
    fstream fil;
    fstream ftemp;
    string msg;
    int line_no=1;
    fil.open("todo.txt", ios::app| ios::in| ios::out);
	cout<<"\nChoose one: 1]Add note 2]Delete note 3]Mark done 4]Report 5]List";
	cin>>n;
	switch(n){
		case 1:
			cout<<"\nEnter task:";
			if(fil){
				getline(cin, msg);
			}
			while (fil) {
		        getline(cin, msg); 
		        if (msg == "-1") 
		           break;  
		        fil<<"\n"<<msg; 
    		} 
			fil.close();
			break;

		case 2:
			int done;
			cout<<"\nEnter task number:";
			cin>>done;
			
			delete_line("todo.txt", done);
			break;

		case 3:
			int del;
			cout<<"\nEnter task number:";
			cin>>del;

			delete_line2("todo.txt", del);
			 break;

		case 4:
	        delete_line3();

			break;

		case 5:
			fil.seekg(1, ios::beg);
			int lno=1;
			while(msg!="\n"){
				if(fil.eof()){
					break;
				}
				getline(fil, msg);
				cout<<"["<<lno<<"]"<<msg<<endl;
				lno++;
			}
			fil.close();
			break;

	}
    return 0;
}

