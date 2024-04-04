//Dr_T Unit 2 COSC-1437 Starter 
/* Task -

Top level solution folder: C_STL_Library_YourLastName

create a single main.cpp that contains code samples and implementations of each of the following topics */

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <cassert>
#include <stack>
#include <set>
#include <utility>
#include <map>
using namespace std; 
typedef map<string, int> MapT;
typedef MapT::const_iterator MapIterT;

//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector1 
{ 
  private:  
      vector<int> vec; 
  public: 
      MyClassVector1 (vector<int> v)  //parameterized constructor
      { 
        vec = v; 
      } 
      void print() 
      { 
          /// print the value of vector 
          for (int i = 0; i < vec.size(); i++) 
          {
              cout << vec[i] << " "; 
          }    
      } 
};

class MyClassVector2
{
  private:
    vector<int> vec2;
  public:
    MyClassVector2 (vector<int> v)
    {
      vec2 = v;
    }
    void print()
    {
      for (int i = 0; i < vec2.size(); i++)
        {
          cout << vec2[i] << " ";
        }
    }
};

class MyClassVector3
{
  private:
    vector<int> vec3;
  public:
    MyClassVector3 (vector<int> v)
    {
      vec3 = v;
    }
    void print()
    {
      for (int i = 0; i < vec3.size(); i++)
        {
          cout << vec3[i] << " ";
        }
    }
};

bool less_than_7(int value)
{
  return value < 7;
}

int main(int argc, char* argv[]) 
{
    /****Section_Name***Vectors*/ 
    //Write the base code for: 5. std::vector example
    vector<double> vd; //vd elments are floating point numbers
    vector<int> vi; //vi elements are integer numbers 
    vector<string> vs; //vs elements are string objects 

    //Expand this code to:

    //add 3 elements to the vd vector
    vd.push_back(1);
    vd.push_back(2);
    vd.push_back(3);
    vd.push_back(55.4); 

    //add 3 elements to the vi vector
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);

   // add 3 elements to the vs vector
    vs.push_back("1");
    vs.push_back("2");
    vs.push_back("3");

   // display the 3 elements in the vd vector
   cout << "\nValues in vd: \n"; 
   for(double vals : vd)
   {
     cout << vals << endl; 
   }
   cout << "\nAnother way to print vector: " << endl; 
   for(int i = 0; i < vd.size(); i++)
   {
     cout << vd[i] << endl; 
   }

    //display the 3 elements in the vi vector
    cout << "\nValues in vi: \n";
    for(int vals : vi)
    {
      cout << vals << endl; 
    }

   // display the 3 elements in the vs vector
   cout << "\nValues in vs: \n";
   for(string vals : vs)
     {
       cout << vals << endl;
     }

    /****Section_Name***Vector_as_Class_Member*/ 
    //Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/

   cout << "\nVector_as_Class_Member" << endl; 
    vector<int> vec; 
        for (int i = 1; i <= 5; i++) 
            vec.push_back(i); 
        MyClassVector1 obj(vec); 
        obj.print(); 
  //Continue with MyClassVector2 and MyClassVector3
        MyClassVector2 obj2(vec);
        obj2.print();

        MyClassVector3 obj3(vec);
        obj3.print();
      

    /****Section_Name***STL_Iterators*/ 
  cout << "\nSTL_Iterators" << endl;
  vector <int> vint (3); //vector with 3 integer numbers
  vint[0] = 10;
  vint[1] = 20;
  vint[2] = 30;
  vector<int>::iterator it;
  for(it = vint.begin(); it != vint.end(); ++it)
    {
      cout << " " << *it;
    }

    /****Section_Name*** Stack*/
  cout << "\nStack" << endl;
  stack <int> st;
  st.push(100); //push number on the stack
  assert(st.size() == 1); //verify one element is on the stack
  assert(st.top() == 100); //verify element value

  st.top() = 456; //assign a new value
  assert(st.top() == 456);

  st.pop(); //remove element
  assert(st.empty() == true);
  

    /****Section_Name**** Set*/
    //Write the code as presented in: 3. std::set
    cout << "\nSet" << endl;
    set<int> iset; //set of unique integer numbers
    iset.insert(11); //populate set with some values
    iset.insert(-11);
    iset.insert(55);
    iset.insert(22);
    iset.insert(22);
    if(iset.find(55) != iset.end()) //is value already stored?
    {
      iset.insert(55);
    }
    assert(iset.size() == 4); //sanity check :-)
    set<int>::iterator set_it;
    for(set_it = iset.begin(); set_it != iset.end(); it++)
      {
        cout << " " << *it;
      }
  
    /****Section_Name****Pair_Structure*/
    //Write the code as presented in: 4. std::pair structure
    cout << "\nPair Structure" << endl;
    pair<string, string> strstr;
    strstr.first = "Hello";
    strstr.second = "World";

  pair< int, string> intstr;
  intstr.first = 1;
  intstr.second = "one";

  pair<string, int> strint("two", 2);
  assert(strint.first == "two");
  assert(strint.second == 2);

    /****Section_Name**** Map_Insert*/
    //Write the code as presented in: 14. std::map::insert
    cout << "\nMap Insert" << endl;
    MapT amap;
    pair<MapIterT, bool> result = amap.insert(make_pair("Fred", 45));

   assert(result.second == true);  
   assert(result.first->second == 45);

   result = amap.insert(make_pair("Fred", 54)); //Fred is already in the map, and result.first
  //simply points there now:
   assert(result.second == false);
   assert(result.first->second == 45);


    /****Section_Name****Map_Summary*/
    //Write the code as presented in: 16. Map summary
    cout << "\nMap Summary" << endl;
    map<string, string> phone_book;
    phone_book["411"] = "Directory";
    phone_book["911"] = "Emergency";
    phone_book["508-678-2811"] = "BCC";
    if(phone_book.find("411") != phone_book.end())
    {
      phone_book.insert(make_pair(string("411"), string("Directory")));  
    }
  assert(phone_book.size() == 3);
  map< string, string>::const_iterator map_it;
  for(map_it = phone_book.begin(); map_it != phone_book.end(); ++it)
    {
      cout << " " << map_it->first << " " << map_it->second << endl;
    }


    /****Section_Name**** Sort_Algorithm*/
    //Write the code as presented in: 23. sort example

    cout << "\nSort Algorithm" << endl;
    int arr[100];
    sort(arr, arr + 100);
    vector<int> v1;
    sort(v1.begin(), v1.end());
  

    /****Section_Name****Predicate_Algorithm*/
    //Write the code as presented in: 25. count_if and predicate function

  cout << "\nPredicate Algorithm" << endl;
  vector<int> v2;
  int count_less = count_if(v1.begin(), v1.end(), less_than_7);
  cout << "The number of values less than 7 is: " << count_less << endl;
  
    return 0;
 }