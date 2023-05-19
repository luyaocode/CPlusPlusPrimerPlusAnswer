#ifndef CHAPTER17_H__
#define CHAPTER17_H__
#include <string>
#include <vector>
using namespace std;
void trnansNumber();

void printInfo();

void count$();

void cin2File();

void copyAlltypeFile(int argc, char* argv[]);

void combineTexts(const string file1, const string file2);

void ourMutualFriends();

void testBinaryIO();
void showStr(const string& s);
class Store
{
private:
	ofstream& ofs;
public:
	Store(ofstream& o) :ofs(o) {}
	void operator()(const string& s);
};
void getStrs(ifstream& ifs, vector<string>& vsi);



#endif
