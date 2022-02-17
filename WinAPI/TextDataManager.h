#pragma once
#include "SingletonBase.h"

/*
#include <fstream>
FILE* file;
Text	>> ����� �ſ� ������ ������ ������ ����ϴ�
xml		>> ��ȣȭ�� �ϱ������� �� ������ �����ʴ�.
json	>> java�� ���� �Ļ� c++���� ��밡��
ini		>> ���� ������ �Ǵ� ���� �����Ҷ� ����. ex)�ɼ�
*/

#define SAVE_BUFFER 128
#define LOAD_BUFFER 128

class TextDataManager : public SingletonBase<TextDataManager>
{
private:

public:
	HRESULT init(void);
	void release(void);

	void save(const char* fileName, vector<string> vStr);
	char* vectorArrayCombine(vector<string> vArray);

	vector<string> load(const char* fileName);
	vector<string> charArraySeparation(char charArray[]);

	TextDataManager() {}
	~TextDataManager() {}
};

