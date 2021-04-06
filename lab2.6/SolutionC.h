#pragma once
#include <string>

using namespace std;
class SolutionC
{
private:
	int amount; // Відносна к-сть речовини
	static int counter;
public:
	class Liquid
	{
	private:
		string name; // Назва рідини
		int density; // Густина
		static int counter;
	public:
		string getName() const { return name; };
		int getDensity() const { return density; };

		void setName(string value) { name = value; };
		void setDensity(int value) { density = value; };

		void Init(string name, int  density);
		void Display() const;
		void Read();
		string toString() const;


		Liquid();
		Liquid(const string name);
		Liquid(const int density);
		Liquid(const string name, const int density);
		Liquid(const Liquid& m);
		Liquid& operator = (const Liquid& m);
		friend ostream& operator << (ostream& out, const Liquid& m);
		friend istream& operator >> (istream& in, Liquid& m);
		operator string () const;
		Liquid& operator ++ ();
		Liquid& operator -- ();
		Liquid operator ++ (int);
		Liquid operator -- (int);
		~Liquid(void);

		static int getCounter();
	};
	Liquid liquid;
public:
	SolutionC::Liquid getLiquid() const { return liquid; };
	int getAmount() const { return amount; };

	void setLiquid(SolutionC::Liquid value) { liquid = value; };
	void setAmount(int value) { amount = value; };

	void Init(SolutionC::Liquid liquid, int  amount);
	void Display() const;
	void Read();
	string toString() const;

	SolutionC(const string name = "", const int density = 0, const int amount = 0);
	SolutionC(const SolutionC& s);
	SolutionC& operator = (const SolutionC& s);
	friend ostream& operator << (ostream& out, const SolutionC& s);
	friend istream& operator >> (istream& in, SolutionC& s);
	operator string () const;
	SolutionC& operator ++ ();
	SolutionC& operator -- ();
	SolutionC operator ++ (int);
	SolutionC operator -- (int);
	~SolutionC(void);

	static int getCounter();
};
