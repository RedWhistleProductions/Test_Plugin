#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

class FileIO{
public:
	const bool DEBUG = false;
	std::string File;
	std::string Path;

	std::ofstream oFile;
	std::ifstream iFile;

	std::string Mode;
	bool Append;
	bool IsOpen;
	
	

	FileIO();
	FileIO(std::string file);
	~FileIO();

	bool Open();
	bool Open(std::string file);
	void Close();
	void NoSpaces();
	
	int I();
	std::string S();
	float F();
	double D();
		
	void Read(std::string &Str);
	FileIO& operator>>(std::string &Str);

	void Read(int &num);
	FileIO& operator>>(int &num);

	void Read(float &num);
	FileIO& operator>>(float &num);

	void Read(double &num);
	FileIO& operator>>(double &num);

	void Write(std::string Str);
	FileIO& operator<<(std::string);
	FileIO& operator<(std::string Str);

	void Write(int num);
	FileIO& operator<<(int num);

	void Write(float num);
	FileIO& operator<<(float num);

	void Write(double num);
	FileIO& operator<<(double num);

	bool Good();
	bool End();
};
