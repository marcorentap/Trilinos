// @HEADER
// *****************************************************************************
//                           Sacado Package
//
// Copyright 2006 NTESS and the Sacado contributors.
// SPDX-License-Identifier: LGPL-2.1-or-later
// *****************************************************************************
// @HEADER

/* Try to test all combinations of types and operations */



#define ADT_RAD Sacado::Rad::



#include "Sacado_trad.hpp"

#include <cstdio>

using std::printf;



typedef ADT_RAD IndepADvar<double> AI;

typedef ADT_RAD ADvar<double> A;

typedef ADT_RAD ConstADvar<double> C;

typedef ADT_RAD ADvari<double> Ai;

typedef const ADT_RAD IndepADvar<double> cAI;

typedef const ADT_RAD ADvar<double> cA;

typedef const ADT_RAD ConstADvar<double> cC;

typedef const ADT_RAD ADvari<double> cAi;

static int rc;



/* This is to be run through an awk program that changes lines */

/* with "BINTEST" or "UNOPTEST" at the beginning of the line into */

/* a the desired C++ (which we can then inspect). */



 void

botch(const char *what, double wanted, double got)

{

	printf("%s: expected %g, got %g, diff = %.2g\n", what, wanted, got, wanted-got);

	rc = 1;

	}



 const double tol = 5e-16;



 int

differ(double a, double b)

{

	double d = a - b;

	if (d < 0.)

		d = -d;

	if (a < 0.)

		a = -a;

	if (b < 0.)

		b = -b;

	if (a < b)

		a = b;

	if (a > 0.)

		d /= a;

	return d > tol;

	}



#ifndef RAD_EQ_ALIAS

#define Plus_dx 1.

#else

#ifdef RAD_AUTO_AD_Const

#define Plus_dx 1.

#else

#define Plus_dx 0.

#endif

#endif



 int

main(void)

{

	AI xAI, yAI;

	A fA, xA, yA;

	C xC, yC;

        double dx, f, xd;



	rc = 0;


	/**** Test of fabs ****/

	xd = -12.; f = 12.; dx = -1.;
	xAI = xd;
	fA = fabs(xAI);
	A::Gradcomp();
	if (differ(fA.val(), f)) botch("fA = fabs(xAI)", f, fA.val());
	else if (differ(xAI.adj(), dx)) botch("d fabs(xAI)/dx", dx, xAI.adj());
	{
	A::aval_reset();
	cAI xcAI(xd);
	fA = fabs(xcAI);
	A::Gradcomp();
	if (differ(fA.val(), f)) botch("fA = fabs(xcAI)", f, fA.val());
	else if (differ(xcAI.adj(), dx)) botch("d fabs(xcAI)/dx", dx, xcAI.adj());
	}
	xA = xd;
	fA = fabs(xA);
	A::Gradcomp();
	if (differ(fA.val(), f)) botch("fA = fabs(xA)", f, fA.val());
	else if (differ(xA.adj(), dx)) botch("d fabs(xA)/dx", dx, xA.adj());
	{
	A::aval_reset();
	cA xcA(xd);
	fA = fabs(xcA);
	A::Gradcomp();
	if (differ(fA.val(), f)) botch("fA = fabs(xcA)", f, fA.val());
	else if (differ(xcA.adj(), dx)) botch("d fabs(xcA)/dx", dx, xcA.adj());
	}
	xC = xd;
	fA = fabs(xC);
	A::Gradcomp();
	if (differ(fA.val(), f)) botch("fA = fabs(xC)", f, fA.val());
	else if (differ(xC.adj(), dx)) botch("d fabs(xC)/dx", dx, xC.adj());
	{
	A::aval_reset();
	cC xcC(xd);
	fA = fabs(xcC);
	A::Gradcomp();
	if (differ(fA.val(), f)) botch("fA = fabs(xcC)", f, fA.val());
	else if (differ(xcC.adj(), dx)) botch("d fabs(xcC)/dx", dx, xcC.adj());
	}
	{
	cAi xcAi(xd);
	fA = fabs(xcAi);
	A::Gradcomp();
	if (differ(fA.val(), f)) botch("fA = fabs(xcAi)", f, fA.val());
	else if (differ(xcAi.aval, dx)) botch("d fabs(xcAi)/dx", dx, xcAi.aval);
	}
	{
	A::aval_reset();
	cAi xcAi(xd);
	fA = fabs(xcAi);
	A::Gradcomp();
	if (differ(fA.val(), f)) botch("fA = fabs(xcAi)", f, fA.val());
	else if (differ(xcAi.aval, dx)) botch("d fabs(xcAi)/dx", dx, xcAi.aval);
	}


	if (!rc) // chatter for cppunit test, which cannot tolerate silence

		printf("OK\n");

	return rc;

	}
