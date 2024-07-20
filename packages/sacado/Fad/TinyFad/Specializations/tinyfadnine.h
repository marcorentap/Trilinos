// @HEADER
// *****************************************************************************
//                           Sacado Package
//
// Copyright 2006 NTESS and the Sacado contributors.
// SPDX-License-Identifier: LGPL-2.1-or-later
// *****************************************************************************
// @HEADER

#ifndef _tinyfadnine_h_
#define _tinyfadnine_h_

//*********************************************************
// This file is generated by generate.cc.
// Use this file for any modification
//*********************************************************

template <class T> class TinyFad<9,T> {
public:
  typedef T value_type;
  typedef T grad_type;
protected:

  int n;
  T val_;

  T dx0_;
  T dx1_;
  T dx2_;
  T dx3_;
  T dx4_;
  T dx5_;
  T dx6_;
  T dx7_;
  T dx8_;


public:
  void diff(const size_t ith, const size_t sz){
     n = ith+1;
     dx0_ = T(0.);
     dx1_ = T(0.);
     dx2_ = T(0.);
     dx3_ = T(0.);
     dx4_ = T(0.);
     dx5_ = T(0.);
     dx6_ = T(0.);
     dx7_ = T(0.);
     dx8_ = T(0.);

     switch(ith){
     case 0 : dx0_ = T(1.);break;
     case 1 : dx1_ = T(1.);break;
     case 2 : dx2_ = T(1.);break;
     case 3 : dx3_ = T(1.);break;
     case 4 : dx4_ = T(1.);break;
     case 5 : dx5_ = T(1.);break;
     case 6 : dx6_ = T(1.);break;
     case 7 : dx7_ = T(1.);break;
     case 8 : dx8_ = T(1.);break;
     default : std::cout << "ith = " << ith << "  out of definition set" << std::endl;exit(1);
     }
  }

  TinyFad(const T& ind, const int ini) : n(ini+1), val_(ind) {
     dx0_ = T(0.);
     dx1_ = T(0.);
     dx2_ = T(0.);
     dx3_ = T(0.);
     dx4_ = T(0.);
     dx5_ = T(0.);
     dx6_ = T(0.);
     dx7_ = T(0.);
     dx8_ = T(0.);

     switch(ini){
     case 0 : dx0_ = T(1.);break;
     case 1 : dx1_ = T(1.);break;
     case 2 : dx2_ = T(1.);break;
     case 3 : dx3_ = T(1.);break;
     case 4 : dx4_ = T(1.);break;
     case 5 : dx5_ = T(1.);break;
     case 6 : dx6_ = T(1.);break;
     case 7 : dx7_ = T(1.);break;
     case 8 : dx8_ = T(1.);break;
     default : std::cout << "ini = " << ini << "  out of definition set" << std::endl;exit(1);
     }
  }
  TinyFad() : n(0), val_(0.) {
     dx0_ = T(0.);
     dx1_ = T(0.);
     dx2_ = T(0.);
     dx3_ = T(0.);
     dx4_ = T(0.);
     dx5_ = T(0.);
     dx6_ = T(0.);
     dx7_ = T(0.);
     dx8_ = T(0.);
  }
  TinyFad(const No_Initialization &): n(0) {}
  TinyFad(const T& in) : n(0), val_(in) {
     dx0_ = T(0.);
     dx1_ = T(0.);
     dx2_ = T(0.);
     dx3_ = T(0.);
     dx4_ = T(0.);
     dx5_ = T(0.);
     dx6_ = T(0.);
     dx7_ = T(0.);
     dx8_ = T(0.);
  }
  TinyFad(const TinyFad<9,T> & in) : n(0), val_(in.val_) {
     dx0_ = in.dx0_;
     dx1_ = in.dx1_;
     dx2_ = in.dx2_;
     dx3_ = in.dx3_;
     dx4_ = in.dx4_;
     dx5_ = in.dx5_;
     dx6_ = in.dx6_;
     dx7_ = in.dx7_;
     dx8_ = in.dx8_;
  }

  ~TinyFad() {}

  int    N()       const {return n-1;}

  const T& val()     const { return val_;}
  T& val()                 { return val_;}

  const T& d0() const { return dx0_;}
  T& d0() { return dx0_;}

  const T& d1() const { return dx1_;}
  T& d1() { return dx1_;}

  const T& d2() const { return dx2_;}
  T& d2() { return dx2_;}

  const T& d3() const { return dx3_;}
  T& d3() { return dx3_;}

  const T& d4() const { return dx4_;}
  T& d4() { return dx4_;}

  const T& d5() const { return dx5_;}
  T& d5() { return dx5_;}

  const T& d6() const { return dx6_;}
  T& d6() { return dx6_;}

  const T& d7() const { return dx7_;}
  T& d7() { return dx7_;}

  const T& d8() const { return dx8_;}
  T& d8() { return dx8_;}

  T& dx(int i){
     switch(i){
     case 0 : return dx0_;
     case 1 : return dx1_;
     case 2 : return dx2_;
     case 3 : return dx3_;
     case 4 : return dx4_;
     case 5 : return dx5_;
     case 6 : return dx6_;
     case 7 : return dx7_;
     case 8 : return dx8_;
     default : std::cout << "i out of bounds" << std::endl;exit(1);
     }
  }
  const T& dx(int i) const {
     switch(i){
     case 0 : return dx0_;
     case 1 : return dx1_;
     case 2 : return dx2_;
     case 3 : return dx3_;
     case 4 : return dx4_;
     case 5 : return dx5_;
     case 6 : return dx6_;
     case 7 : return dx7_;
     case 8 : return dx8_;
     default : std::cout << "i out of bounds" << std::endl;exit(1);
     }
  }
  T& d(int i){
     switch(i){
     case 0 : return dx0_;
     case 1 : return dx1_;
     case 2 : return dx2_;
     case 3 : return dx3_;
     case 4 : return dx4_;
     case 5 : return dx5_;
     case 6 : return dx6_;
     case 7 : return dx7_;
     case 8 : return dx8_;
     default : std::cout << "i out of bounds" << std::endl;exit(1);
     }
  }
  const T& d(int i) const {
     switch(i){
     case 0 : return dx0_;
     case 1 : return dx1_;
     case 2 : return dx2_;
     case 3 : return dx3_;
     case 4 : return dx4_;
     case 5 : return dx5_;
     case 6 : return dx6_;
     case 7 : return dx7_;
     case 8 : return dx8_;
     default : std::cout << "i out of bounds" << std::endl;exit(1);
     }
  }

  TinyFad<9,T> & operator = (const TinyFad<9,T> & in){
     val_ = in.val_;

     dx0_ = in.dx0_;
     dx1_ = in.dx1_;
     dx2_ = in.dx2_;
     dx3_ = in.dx3_;
     dx4_ = in.dx4_;
     dx5_ = in.dx5_;
     dx6_ = in.dx6_;
     dx7_ = in.dx7_;
     dx8_ = in.dx8_;

     return *this;
  }

  TinyFad<9,T> & operator = (const T & in){
     val_ = in;

     dx0_ = T(0.);
     dx1_ = T(0.);
     dx2_ = T(0.);
     dx3_ = T(0.);
     dx4_ = T(0.);
     dx5_ = T(0.);
     dx6_ = T(0.);
     dx7_ = T(0.);
     dx8_ = T(0.);

     return *this;
  }

  TinyFad<9,T> & operator += (const TinyFad<9,T> & in){
     dx0_ += in.dx0_;
     dx1_ += in.dx1_;
     dx2_ += in.dx2_;
     dx3_ += in.dx3_;
     dx4_ += in.dx4_;
     dx5_ += in.dx5_;
     dx6_ += in.dx6_;
     dx7_ += in.dx7_;
     dx8_ += in.dx8_;
     val_ += in.val_;


    return *this;
  }
  TinyFad<9,T> & operator -= (const TinyFad<9,T> & in){
     dx0_ -= in.dx0_;
     dx1_ -= in.dx1_;
     dx2_ -= in.dx2_;
     dx3_ -= in.dx3_;
     dx4_ -= in.dx4_;
     dx5_ -= in.dx5_;
     dx6_ -= in.dx6_;
     dx7_ -= in.dx7_;
     dx8_ -= in.dx8_;
     val_ -= in.val_;

     return *this;
  }
  TinyFad<9,T> & operator *= (const TinyFad<9,T> & in){
     dx0_ = dx0_ * in.val_ + val_ * in.dx0_;
     dx1_ = dx1_ * in.val_ + val_ * in.dx1_;
     dx2_ = dx2_ * in.val_ + val_ * in.dx2_;
     dx3_ = dx3_ * in.val_ + val_ * in.dx3_;
     dx4_ = dx4_ * in.val_ + val_ * in.dx4_;
     dx5_ = dx5_ * in.val_ + val_ * in.dx5_;
     dx6_ = dx6_ * in.val_ + val_ * in.dx6_;
     dx7_ = dx7_ * in.val_ + val_ * in.dx7_;
     dx8_ = dx8_ * in.val_ + val_ * in.dx8_;
     val_ *= in.val_;

     return *this;
  }
  TinyFad<9,T> & operator /= (const TinyFad<9,T> & in){
     if (in.val_ == 0.) error("TinyFad & TinyFad::operator /= (const TinyFad & in), dividing by 0");
     dx0_ = ( dx0_ * in.val_ - val_ * in.dx0_ ) / in.val_ / in.val_ ;
     dx1_ = ( dx1_ * in.val_ - val_ * in.dx1_ ) / in.val_ / in.val_ ;
     dx2_ = ( dx2_ * in.val_ - val_ * in.dx2_ ) / in.val_ / in.val_ ;
     dx3_ = ( dx3_ * in.val_ - val_ * in.dx3_ ) / in.val_ / in.val_ ;
     dx4_ = ( dx4_ * in.val_ - val_ * in.dx4_ ) / in.val_ / in.val_ ;
     dx5_ = ( dx5_ * in.val_ - val_ * in.dx5_ ) / in.val_ / in.val_ ;
     dx6_ = ( dx6_ * in.val_ - val_ * in.dx6_ ) / in.val_ / in.val_ ;
     dx7_ = ( dx7_ * in.val_ - val_ * in.dx7_ ) / in.val_ / in.val_ ;
     dx8_ = ( dx8_ * in.val_ - val_ * in.dx8_ ) / in.val_ / in.val_ ;
     val_ /= in.val_;

     return *this;
  }

  TinyFad<9,T> & operator += (const T & in){     val_ += in;

     return *this;
  }
  TinyFad<9,T> & operator -= (const T & in){     val_ -= in;

     return *this;
  }
  TinyFad<9,T> & operator *= (const T & in){
     val_ *= in;

     dx0_ *= in;
     dx1_ *= in;
     dx2_ *= in;
     dx3_ *= in;
     dx4_ *= in;
     dx5_ *= in;
     dx6_ *= in;
     dx7_ *= in;
     dx8_ *= in;

     return *this;
  }
  TinyFad<9,T> & operator /= (const T & in){
     if ( in == T(0.) ) error("TinyFad & TinyFad::operator /= (const T & in), dividing by 0");
     val_ /= in;

     dx0_ /= in;
     dx1_ /= in;
     dx2_ /= in;
     dx3_ /= in;
     dx4_ /= in;
     dx5_ /= in;
     dx6_ /= in;
     dx7_ /= in;
     dx8_ /= in;

     return *this;
  }

  TinyFad<9,T> operator++(int){
     TinyFad<9,T> tmp(*this);
     tmp.val_++;
     return tmp;
  };
  TinyFad<9,T> operator--(int){
     TinyFad<9,T> tmp(*this);
     tmp.val_--;
     return tmp;
  };
  TinyFad<9,T> & operator++(){     ++val_;
     return *this;
  }
  TinyFad<9,T> & operator--(){     --val_;
     return *this;
  }
};


template <class T> inline TinyFad<9,T> operator + (const TinyFad<9,T>& in)
{
  return TinyFad<9,T>(in);
}

template <class T> inline TinyFad<9,T> operator - (const TinyFad<9,T>& in)
{
  TinyFad<9,T> tmp;
  tmp -= in;
  return tmp;
}

template <class L, class R> inline
TinyFad<9,typename NumericalTraits<L,R>::promote >
operator +(const TinyFad<9,L>& un, const TinyFad<9,R>& deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );

  tmp.d0() = un.d0() + deux.d0();

  tmp.d1() = un.d1() + deux.d1();

  tmp.d2() = un.d2() + deux.d2();

  tmp.d3() = un.d3() + deux.d3();

  tmp.d4() = un.d4() + deux.d4();

  tmp.d5() = un.d5() + deux.d5();

  tmp.d6() = un.d6() + deux.d6();

  tmp.d7() = un.d7() + deux.d7();

  tmp.d8() = un.d8() + deux.d8();

  tmp.val() = un.val() + deux.val();

  return tmp;
}

template <class L, class R> inline
TinyFad<9,typename NumericalTraits<L,R>::promote>
operator +(const TinyFad<9,L>& un, const R& deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );

  tmp.d0() = un.d0();

  tmp.d1() = un.d1();

  tmp.d2() = un.d2();

  tmp.d3() = un.d3();

  tmp.d4() = un.d4();

  tmp.d5() = un.d5();

  tmp.d6() = un.d6();

  tmp.d7() = un.d7();

  tmp.d8() = un.d8();

  tmp.val() = un.val() + deux;

  return tmp;
}

template <class L, class R> inline
TinyFad<9,typename NumericalTraits<L,R>::promote >
operator +(const L& un, const TinyFad<9,R>& deux) {
  return operator +(deux,un);
}

template <class L, class R> inline
TinyFad<9,typename NumericalTraits<L,R>::promote >
operator *(const TinyFad<9,L>& un, const TinyFad<9,R>& deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );

  tmp.d0() = un.d0()*deux.val() + un.val() * deux.d0();

  tmp.d1() = un.d1()*deux.val() + un.val() * deux.d1();

  tmp.d2() = un.d2()*deux.val() + un.val() * deux.d2();

  tmp.d3() = un.d3()*deux.val() + un.val() * deux.d3();

  tmp.d4() = un.d4()*deux.val() + un.val() * deux.d4();

  tmp.d5() = un.d5()*deux.val() + un.val() * deux.d5();

  tmp.d6() = un.d6()*deux.val() + un.val() * deux.d6();

  tmp.d7() = un.d7()*deux.val() + un.val() * deux.d7();

  tmp.d8() = un.d8()*deux.val() + un.val() * deux.d8();

  tmp.val() = un.val() * deux.val();

  return tmp;
}

template <class L, class R> inline
TinyFad<9,typename NumericalTraits<L,R>::promote >
operator *(const TinyFad<9,L>& un, const R& deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );

  tmp.d0() = un.d0()*deux;

  tmp.d1() = un.d1()*deux;

  tmp.d2() = un.d2()*deux;

  tmp.d3() = un.d3()*deux;

  tmp.d4() = un.d4()*deux;

  tmp.d5() = un.d5()*deux;

  tmp.d6() = un.d6()*deux;

  tmp.d7() = un.d7()*deux;

  tmp.d8() = un.d8()*deux;

  tmp.val() = un.val() * deux;

  return tmp;
}

template <class L, class R> inline
TinyFad<9,typename NumericalTraits<L,R>::promote >
operator *(const L& un, const TinyFad<9,R>& deux) {

  return operator *(deux,un);
}


template <class L, class R> inline
TinyFad<9,typename NumericalTraits<L,R>::promote >
operator -(const TinyFad<9,L> & un, const TinyFad<9,R> & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );

  tmp.d0() = un.d0() - deux.d0();

  tmp.d1() = un.d1() - deux.d1();

  tmp.d2() = un.d2() - deux.d2();

  tmp.d3() = un.d3() - deux.d3();

  tmp.d4() = un.d4() - deux.d4();

  tmp.d5() = un.d5() - deux.d5();

  tmp.d6() = un.d6() - deux.d6();

  tmp.d7() = un.d7() - deux.d7();

  tmp.d8() = un.d8() - deux.d8();

  tmp.val() = un.val() - deux.val();

  return tmp;
}

template <class L, class R> inline
TinyFad<9,typename NumericalTraits<L,R>::promote>
operator -(const L & un, const TinyFad<9,R> & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );

  tmp.d0() -= deux.d0();

  tmp.d1() -= deux.d1();

  tmp.d2() -= deux.d2();

  tmp.d3() -= deux.d3();

  tmp.d4() -= deux.d4();

  tmp.d5() -= deux.d5();

  tmp.d6() -= deux.d6();

  tmp.d7() -= deux.d7();

  tmp.d8() -= deux.d8();

  tmp.val() = un - deux.val();

  return tmp;
}

template <class L, class R> inline
TinyFad<9, typename NumericalTraits<L,R>::promote >
operator -(const TinyFad<9,L> & un, const R & deux) {
  typedef typename NumericalTraits<L,R>::promote value_type;

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );

  tmp.d0() = un.d0();

  tmp.d1() = un.d1();

  tmp.d2() = un.d2();

  tmp.d3() = un.d3();

  tmp.d4() = un.d4();

  tmp.d5() = un.d5();

  tmp.d6() = un.d6();

  tmp.d7() = un.d7();

  tmp.d8() = un.d8();

  tmp.val() = un.val() - deux;

  return tmp;
}

template <class L, class R> inline
TinyFad<9, typename NumericalTraits<L,R>::promote >
operator /(const TinyFad<9,L> & un, const TinyFad<9,R> & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  if (deux.val() == 0.) error("TinyFad & TinyFad::operator /(const TinyFad<9,L> & un, const TinyFad<9,R> & deux), dividing by 0");

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );
  value_type dval = deux.val();

  tmp.d0() = ( un.d0()* deux.val() - un.val() * deux.d0() ) / dval / dval ;

  tmp.d1() = ( un.d1()* deux.val() - un.val() * deux.d1() ) / dval / dval ;

  tmp.d2() = ( un.d2()* deux.val() - un.val() * deux.d2() ) / dval / dval ;

  tmp.d3() = ( un.d3()* deux.val() - un.val() * deux.d3() ) / dval / dval ;

  tmp.d4() = ( un.d4()* deux.val() - un.val() * deux.d4() ) / dval / dval ;

  tmp.d5() = ( un.d5()* deux.val() - un.val() * deux.d5() ) / dval / dval ;

  tmp.d6() = ( un.d6()* deux.val() - un.val() * deux.d6() ) / dval / dval ;

  tmp.d7() = ( un.d7()* deux.val() - un.val() * deux.d7() ) / dval / dval ;

  tmp.d8() = ( un.d8()* deux.val() - un.val() * deux.d8() ) / dval / dval ;

  tmp.val() = un.val() / dval;

  return tmp;
}

template <class L, class R> inline
TinyFad<9, typename NumericalTraits<L,R>::promote >
operator /(const L & un, const TinyFad<9,R> & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  if (deux.val() == 0.) error("TinyFad & TinyFad::operator /(const L & un, const TinyFad<9,R> & deux), dividing by 0");

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );
  value_type dval = deux.val();

  tmp.d0() = - un * deux.d0()  / dval / dval ;

  tmp.d1() = - un * deux.d1()  / dval / dval ;

  tmp.d2() = - un * deux.d2()  / dval / dval ;

  tmp.d3() = - un * deux.d3()  / dval / dval ;

  tmp.d4() = - un * deux.d4()  / dval / dval ;

  tmp.d5() = - un * deux.d5()  / dval / dval ;

  tmp.d6() = - un * deux.d6()  / dval / dval ;

  tmp.d7() = - un * deux.d7()  / dval / dval ;

  tmp.d8() = - un * deux.d8()  / dval / dval ;

  tmp.val() = un / dval;

  return tmp;
}

template <class  L, class R> inline
TinyFad<9, typename NumericalTraits<L,R>::promote >
operator /(const TinyFad<9,L> & un, const R & deux) {

  typedef typename NumericalTraits<L,R>::promote value_type;

  if (deux == 0.) error("TinyFad & TinyFad::operator /(const TinyFad<9,L> & un, const R & deux), dividing by 0");

  No_Initialization nothing;
  TinyFad<9,value_type> tmp( nothing );

  tmp.d0() = un.d0()  / deux;

  tmp.d1() = un.d1()  / deux;

  tmp.d2() = un.d2()  / deux;

  tmp.d3() = un.d3()  / deux;

  tmp.d4() = un.d4()  / deux;

  tmp.d5() = un.d5()  / deux;

  tmp.d6() = un.d6()  / deux;

  tmp.d7() = un.d7()  / deux;

  tmp.d8() = un.d8()  / deux;

  tmp.val() = un.val() / deux;

   return tmp;
}

template <class T> TinyFad<9,T> exp (const TinyFad<9,T>& in)
{
  TinyFad<9,T> tmp(exp(in.val()));

  tmp.d0() = in.d0()*exp(in.val());
  tmp.d1() = in.d1()*exp(in.val());
  tmp.d2() = in.d2()*exp(in.val());
  tmp.d3() = in.d3()*exp(in.val());
  tmp.d4() = in.d4()*exp(in.val());
  tmp.d5() = in.d5()*exp(in.val());
  tmp.d6() = in.d6()*exp(in.val());
  tmp.d7() = in.d7()*exp(in.val());
  tmp.d8() = in.d8()*exp(in.val());

  return tmp;
}

template <class T> TinyFad<9,T> log (const TinyFad<9,T>& in)
{
  if ( in.val() <= 0) error("TinyFad log (const TinyFad& in) : zero or negative value");
  TinyFad<9,T> tmp(log(in.val()));

  tmp.d0() = in.d0() / in.val();
  tmp.d1() = in.d1() / in.val();
  tmp.d2() = in.d2() / in.val();
  tmp.d3() = in.d3() / in.val();
  tmp.d4() = in.d4() / in.val();
  tmp.d5() = in.d5() / in.val();
  tmp.d6() = in.d6() / in.val();
  tmp.d7() = in.d7() / in.val();
  tmp.d8() = in.d8() / in.val();

  return tmp;
}

template <class T> TinyFad<9,T> sqrt (const TinyFad<9,T>& in)
{
  if ( in.val() < 0. ) error("TinyFad<9,T> sqrt (const TinyFad& in) : negative value");
  TinyFad<9,T> tmp(sqrt(in.val()));

  bool test=true;
  if ( in.val() == T(0.) ){
    if ( in.d0() != T(0.) ) test = false;

    if ( in.d1() != T(0.) ) test = false;

    if ( in.d2() != T(0.) ) test = false;

    if ( in.d3() != T(0.) ) test = false;

    if ( in.d4() != T(0.) ) test = false;

    if ( in.d5() != T(0.) ) test = false;

    if ( in.d6() != T(0.) ) test = false;

    if ( in.d7() != T(0.) ) test = false;

    if ( in.d8() != T(0.) ) test = false;

    if ( !test )
      error("TinyFad<9,T> sqrt (const TinyFad& in) : null value");
  }
  else {
    tmp.d0() = in.d0() / sqrt(in.val()) / 2.;
    tmp.d1() = in.d1() / sqrt(in.val()) / 2.;
    tmp.d2() = in.d2() / sqrt(in.val()) / 2.;
    tmp.d3() = in.d3() / sqrt(in.val()) / 2.;
    tmp.d4() = in.d4() / sqrt(in.val()) / 2.;
    tmp.d5() = in.d5() / sqrt(in.val()) / 2.;
    tmp.d6() = in.d6() / sqrt(in.val()) / 2.;
    tmp.d7() = in.d7() / sqrt(in.val()) / 2.;
    tmp.d8() = in.d8() / sqrt(in.val()) / 2.;
  }

  return tmp;
}

template <class T> TinyFad<9,T> sin (const TinyFad<9,T>& in)
{
  TinyFad<9,T> tmp( sin(in.val()) );

  tmp.d0() = in.d0() * cos( in.val() );
  tmp.d1() = in.d1() * cos( in.val() );
  tmp.d2() = in.d2() * cos( in.val() );
  tmp.d3() = in.d3() * cos( in.val() );
  tmp.d4() = in.d4() * cos( in.val() );
  tmp.d5() = in.d5() * cos( in.val() );
  tmp.d6() = in.d6() * cos( in.val() );
  tmp.d7() = in.d7() * cos( in.val() );
  tmp.d8() = in.d8() * cos( in.val() );

  return tmp;
}

template <class T> TinyFad<9,T> cos (const TinyFad<9,T>& in)
{
  TinyFad<9,T> tmp(cos(in.val()));

  tmp.d0() = - in.d0() * sin( in.val() );
  tmp.d1() = - in.d1() * sin( in.val() );
  tmp.d2() = - in.d2() * sin( in.val() );
  tmp.d3() = - in.d3() * sin( in.val() );
  tmp.d4() = - in.d4() * sin( in.val() );
  tmp.d5() = - in.d5() * sin( in.val() );
  tmp.d6() = - in.d6() * sin( in.val() );
  tmp.d7() = - in.d7() * sin( in.val() );
  tmp.d8() = - in.d8() * sin( in.val() );

  return tmp;
}

template <class T> TinyFad<9,T> tan (const TinyFad<9,T>& in)
{
  if ( in.val() == 0) error("TinyFad tan (const TinyFad& in) undiefined in 0.");
  TinyFad<9,T> tmp(tan(in.val()));

  T cosinus = cos(in.val());
  tmp.d0() = in.d0() / cosinus / cosinus;
  tmp.d1() = in.d1() / cosinus / cosinus;
  tmp.d2() = in.d2() / cosinus / cosinus;
  tmp.d3() = in.d3() / cosinus / cosinus;
  tmp.d4() = in.d4() / cosinus / cosinus;
  tmp.d5() = in.d5() / cosinus / cosinus;
  tmp.d6() = in.d6() / cosinus / cosinus;
  tmp.d7() = in.d7() / cosinus / cosinus;
  tmp.d8() = in.d8() / cosinus / cosinus;

  return tmp;
}

template <class T> TinyFad<9,T> pow (const TinyFad<9,T>& in, double e)
{
  TinyFad<9,T> tmp(pow(in.val(), e));

  tmp.d0() = e*in.d0()*pow(in.val(), e-1);
  tmp.d1() = e*in.d1()*pow(in.val(), e-1);
  tmp.d2() = e*in.d2()*pow(in.val(), e-1);
  tmp.d3() = e*in.d3()*pow(in.val(), e-1);
  tmp.d4() = e*in.d4()*pow(in.val(), e-1);
  tmp.d5() = e*in.d5()*pow(in.val(), e-1);
  tmp.d6() = e*in.d6()*pow(in.val(), e-1);
  tmp.d7() = e*in.d7()*pow(in.val(), e-1);
  tmp.d8() = e*in.d8()*pow(in.val(), e-1);

  return tmp;
}

template <class T> TinyFad<9,T> pow (const TinyFad<9,T>& un, const TinyFad<9,T>& deux)
{
  if (un.val() == 0) error("TinyFad pow (const TinyFad& un, const TinyFad& deux), un = 0. ");
  TinyFad<9,T> tmp(pow(un.val(), deux.val()));

  tmp.d0() = deux.d0() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d0() * pow(un.val(), deux.val()-1);
  tmp.d1() = deux.d1() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d1() * pow(un.val(), deux.val()-1);
  tmp.d2() = deux.d2() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d2() * pow(un.val(), deux.val()-1);
  tmp.d3() = deux.d3() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d3() * pow(un.val(), deux.val()-1);
  tmp.d4() = deux.d4() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d4() * pow(un.val(), deux.val()-1);
  tmp.d5() = deux.d5() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d5() * pow(un.val(), deux.val()-1);
  tmp.d6() = deux.d6() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d6() * pow(un.val(), deux.val()-1);
  tmp.d7() = deux.d7() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d7() * pow(un.val(), deux.val()-1);
  tmp.d8() = deux.d8() * log(un.val()) * pow(un.val(), deux.val())
	    + deux.val() * un.d8() * pow(un.val(), deux.val()-1);

  return tmp;
}

template <class T> TinyFad<9,T> pow (const TinyFad<9,T>& in, const int e)
{
  TinyFad<9,T> tmp( std::pow((double)in.val(), (double)e) );

  tmp.d0() = e*in.d0()*std::pow((double)in.val(), (double)e-1);
  tmp.d1() = e*in.d1()*std::pow((double)in.val(), (double)e-1);
  tmp.d2() = e*in.d2()*std::pow((double)in.val(), (double)e-1);
  tmp.d3() = e*in.d3()*std::pow((double)in.val(), (double)e-1);
  tmp.d4() = e*in.d4()*std::pow((double)in.val(), (double)e-1);
  tmp.d5() = e*in.d5()*std::pow((double)in.val(), (double)e-1);
  tmp.d6() = e*in.d6()*std::pow((double)in.val(), (double)e-1);
  tmp.d7() = e*in.d7()*std::pow((double)in.val(), (double)e-1);
  tmp.d8() = e*in.d8()*std::pow((double)in.val(), (double)e-1);

  return tmp;
}

template <class T> TinyFad<9,T> abs (const TinyFad<9,T>& in)
{
  int sign = in.val() > 0? 1:0;

  if (sign) return in;
  else return (-in);
}

template <class T> std::ostream& operator << (std::ostream& os, const TinyFad<9,T>& a)
{
  os.setf(std::ios::fixed,std::ios::scientific);
  os.width(12);
  os << a.val() << "  [";

  os.width(12);
  os << a.d0();
  os.width(12);
  os << a.d1();
  os.width(12);
  os << a.d2();
  os.width(12);
  os << a.d3();
  os.width(12);
  os << a.d4();
  os.width(12);
  os << a.d5();
  os.width(12);
  os << a.d6();
  os.width(12);
  os << a.d7();
  os.width(12);
  os << a.d8();

  os << "]";

  return os;
}


#endif
