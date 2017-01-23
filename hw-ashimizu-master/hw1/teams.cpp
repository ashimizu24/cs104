#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
		   const string* team2,
		   int len)
{
  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }
  cout << endl;  
}

// You may add additional functions here
string* make_t2(string* names, string* t2, int length, 
  int i, int t2_index){
  if(t2_index == length){

    return t2;
    i= i-1;
  }
  else if(i == 0){
  }
  else{
    t2[t2_index] = names[i];
    cout << i;
    make_t2(names, t2, length, i-1, t2_index+1);
  //  make_t2(names, t2, length, i-1, t2_index);
  }
  return t2;
}

void createteam(string* names, string* t1, 
  string* t2, int l, int index, int t1_index){
//index is the index of where you are in names
//t_index is the 
  if(t1_index == l){
    t2 = make_t2(names, t2, l, (l*2)-1, 0);
    printSolution(t1, t2, l);
  }
  else if(index == (l*2)){ 
  }
  else{
    t1[t1_index] = names[index];
    createteam(names, t1, t2, l, index+1, t1_index+1);
    createteam(names, t1, t2, l,  index+1, t1_index);
  }
}

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }

  ifstream ifile(argv[1]);
  if(ifile.fail()){
    cerr << "File was unable to open" << endl;
    return 1;
  }
  
  int num_names;
  ifile >> num_names;
  if(ifile.fail()){
    cerr << "Unable to read in the number of names" << endl;
    return 1;
  }
  string* names = new string[num_names];
  string word;
  for(int i=0; i<num_names; i++){
    ifile >> word;
    if(ifile.fail()){
      cerr << "Unable to read in name" << endl;
      return 1;
    }
    names[i] = word;
  }
  string* team1 = new string[num_names/2];
  string* team2 = new string[num_names/2];

  createteam(names, team1, team2, num_names/2, 0, 0);

  return 0;
}
