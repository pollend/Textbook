#ifndef	_DATA_H
#define	_DATA_H
class data
{
private:

public:
	data();
	~data();
	
	virtual void on_delete();

	template<class Action>
    void persist(Action& a)
    {};
};

#endif
