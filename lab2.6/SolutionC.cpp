#include "SolutionC.h"
#include<iostream>

#include <string>
#include<sstream>
using namespace std;

int SolutionC::counter = 0;

void SolutionC::Init(SolutionC::Liquid liquid, int  amount)
{
	setLiquid(liquid);
	setAmount(amount);
}
void SolutionC::Display() const
{
	cout << endl;
	cout << " Рідина" << endl;
	liquid.Display();
	cout << toString() << endl;
}
void SolutionC::Read()
{
	int amount;
	cout << "Рідина:" << endl;
	liquid.Read();
	cout << "Відносна к-сть речовини: "; cin >> amount;
	Init(liquid, amount);
}
string SolutionC::toString() const
{
	stringstream sout;

	sout << "Відносна к-сть речовини: " << amount << endl;
	return sout.str();
}

void SolutionC::Liquid::Init(string name, int  density)
{
	setName(name);
	setDensity(density);
}
void SolutionC::Liquid::Display() const
{
	cout << toString();
}
void SolutionC::Liquid::Read()
{
	string name;
	int  density;
	cout << "Введіть назву: "; cin >> name;
	cout << "Введіть густину: "; cin >> density;
	Init(name, density);
}
string SolutionC::Liquid::toString() const
{
	stringstream sout;           // створили об'єкт класу "літерний потік"
	sout << "Назва: " << name << endl;
	sout << "Густина: " << density << endl;
	return sout.str();
}

SolutionC::SolutionC(const string name, const int density, const int amount)
	: liquid(name, density), amount(amount)
{
	SolutionC::counter++;
}

SolutionC::SolutionC(const SolutionC& s)
{
	liquid = s.liquid;
	amount = s.amount;
	SolutionC::counter++;
}
SolutionC& SolutionC::operator = (const SolutionC& s)
{
	liquid = s.liquid;
	amount = s.amount;
	return *this;
}
ostream& operator << (ostream& out, const SolutionC& s)
{
	out << string(s);
	return out;
}
istream& operator >> (istream& in, SolutionC& s)
{
	int amount;
	cout << endl;
	cout << "liquid = ? "; in >>
		s.liquid;
	cout << "amount = ? "; in >> amount;

	s.setAmount(amount);
	return in;
}
SolutionC::operator string () const {
	stringstream ss;
	ss << "amount = " << amount << endl;
	return string(liquid) + ss.str();
}
SolutionC& SolutionC::operator ++ () {
	++liquid;
	return *this;
}
SolutionC& SolutionC::operator -- () {
	--liquid;
	return *this;
}
SolutionC SolutionC::operator ++(int)
{
	SolutionC s(*this);
	liquid++;
	return s;
}
SolutionC SolutionC::operator --(int)
{
	SolutionC s(*this);
	liquid--;
	return s;
}
SolutionC::~SolutionC(void)
{
	SolutionC::counter--;
}
int SolutionC::getCounter() { return SolutionC::counter; } 


int SolutionC::Liquid::counter = 0;
SolutionC::Liquid::Liquid()
	: name(""), density(0)
{}
SolutionC::Liquid::Liquid(const string name
)
	: name(name), density(0)
{
	SolutionC::Liquid::counter++;
}
SolutionC::Liquid::Liquid(const int density)
	: name(""), density(density)
{
	SolutionC::Liquid::counter++;
}
SolutionC::Liquid::Liquid(const string name, const int density)
	: name(name), density(density)
{
	SolutionC::Liquid::counter++;
}
SolutionC::Liquid::Liquid(const SolutionC::Liquid& m)
	: name(m.name), density(m.density)
{
	SolutionC::Liquid::counter--;
}
SolutionC::Liquid& SolutionC::Liquid::operator = (const SolutionC::Liquid& m)
{
	this -> name = m.name;
	this -> density = m.density;
	return *this;
}
ostream& operator <<
(ostream& out, const SolutionC::Liquid& m)
{
	out << string(m);
	return out;
}
istream& operator >>
(istream& in, SolutionC::Liquid& m)
{
	string name;
	int density;
	cout << endl;
	cout << "name = ? "; in >> name;
	cout << "density = ? "; in >> density;
	m.setName(name);
	m.setDensity(density);
	return in;
}
SolutionC::Liquid::operator string () const
{
	stringstream ss;
	ss << endl;
	ss << "name = " << name << endl;
	ss << "density = " << density << endl;
	return ss.str();
}
SolutionC::Liquid& SolutionC::Liquid::operator ++ ()
{
	++density;
	return *this;
}
SolutionC::Liquid& SolutionC::Liquid::operator -- ()
{
	--density;
	return *this;
}
SolutionC::Liquid SolutionC::Liquid::operator ++ (int)
{
	Liquid t(*this);
	density++;
	return t;
}
SolutionC::Liquid SolutionC::Liquid::operator -- (int)
{
	Liquid t(*this);
	density--;
	return t;
}
SolutionC::Liquid::~Liquid(void)
{
	SolutionC::Liquid::counter--;
}

int SolutionC::Liquid::getCounter() { return SolutionC::Liquid::counter; }