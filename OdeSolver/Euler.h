#pragma once

#include <valarray>

#include "OdeFunIF.h"
#include "SolverIF.h"

//Convience for writing out methods
using std::valarray;
using vec = valarray<double>;
using crvec = const vec&;
using rvec = vec&;

class Euler : public SolverIF
{
protected:

	//Vector to hold the function vector
	vec k1;

private:

	//Initalize solving vectors
	virtual void initalizeSolverVectors() override;

public:

	//Default Constrcutor
	Euler() = default;

	//Default Copy Constructor
	Euler(const Euler&) = default;

	//Default Assign operator
	Euler& operator=(const Euler&) = default;

	//Default Destrutor
	virtual ~Euler() = default;

	//Initalize the vector
	virtual void initalize(crvec) override;

	//Get the next time step for rvec
	virtual rvec update(crvec,
						rvec,
						const double&,
						const double&,
						const int&,
						const OdeFunIF*) override;

	//Get the power of the error
	virtual const double getErrorOrder() const override;
};

