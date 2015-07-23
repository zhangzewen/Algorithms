#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<iostream>
#include<map>

#define	TRAIN_DATA_DIR "./data/"
#define TEST_DATA_DIR "./test/"

static std::vector<std::string> TestFiles;
static std::multimap<std::string, std::string> business;  //business类文章集合
static std::multimap<std::string, std::string> autos;     //auto类文章集合
static std::multimap<std::string, std::string> sports;    //sport类文章集合


bool loadData()
{
	DIR* dp;
	struct dirent* dirp;
	TestFiles.clear();
	if ((dp = opendir(TRAIN_DATA_DIR)) == NULL) {
		std::cerr << "open train data error!" << std::endl;
		return false;
	}

	while((dirp = readdir(dp)) != NULL) {
		if (strcmp(dirp->d_name, ".") == 0 ||
			strcmp(dirp->d_name, "..") == 0) {
			continue;
		}
		std::string filename(dirp->d_name);
		TestFiles.push_back(filename);
		if (filename.find("business") != std::string::npos) {
			business.insert(make_pair("business", filename));
		} else if (filename.find("auto") != std::string::npos) {
			autos.insert(make_pair("auto", filename));
		} else if (filename.find("sports") != std::string::npos) {
			sports.insert(make_pair("sports", filename));
		}
	}
}

int main(int argc, char** argv)
{
	loadData();
	for(std::vector<std::string>::const_iterator iter = TestFiles.begin();
			iter != TestFiles.end();
			++iter) {
		std::cout << *iter << std::endl;
	}
	return 0;
}
