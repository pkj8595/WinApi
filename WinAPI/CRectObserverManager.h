#pragma once
#include "ISubject.h"
#include "SingletonBase.h" 

class CRectObserverManager : public SingletonBase< CRectObserverManager>
{
private:
	//map를 쓰는게 좋지않을까?
	typedef vector<IRectObserved*> vRcObserved;
	typedef vector<IRectObserved*>::iterator viRcObserved;

private:
	vRcObserved  _vRect;
	viRcObserved _viRect;
	viRcObserved _viRectCompare;

public:
	HRESULT init(void);
	void release(void);

	virtual void registerObserved(IRectObserved* observed);
	virtual void removeObserved(IRectObserved* observed);
	virtual void getRectFromObserved();

	CRectObserverManager() {}
	~CRectObserverManager() {}
};

