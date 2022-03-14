#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
//#include "../node.hpp"
//#include "../stack.hpp"
#include "../expressionReader.h"
//#include "../arithmetic_expression.hpp"
//#include "../big_integer_arithmetic.hpp"

/*
TEST_CASE("class Node")
{
  Node n(50);
  REQUIRE(n.getValue() == 50);
  REQUIRE(n.getNext() == nullptr);
}

TEST_CASE("class Stack")
{
  Stack s;
  s.push(50);
  REQUIRE(!s.isEmpty());
  REQUIRE(s.pop() == 50);
  REQUIRE(s.isEmpty());
}

TEST_CASE("class Operand")
{
  Operand o("1234567");
  REQUIRE(o.isNegative() == false);
  REQUIRE(o.getValue() == "1234567");
  REQUIRE(o.getLengthOfString() == 7);
  o.pad(4);
  REQUIRE(o.getValue() == "00001234567");
  o.setValue("7654321");
  REQUIRE(o.getValue() == "7654321");
  Operand o2("-1234567");
  REQUIRE(o2.isNegative() == true);
}

TEST_CASE("class ArithmeticExpression")
{
  ArithmeticExpression ae("1234567","23456",'+');
  std::ostringstream oss;
  oss << ae;
  REQUIRE(oss.str() == "1234567 0023456 +");
}



TEST_CASE("class BigIntegerArithmetic")
{
   ArithmeticExpression * ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'+');
   BigIntegerArithmetic bia(ae);
   bia.setUp();
   bia.add();
   REQUIRE(bia.showResults()== "     364287463834623846283426384\n    +923742938742934723947239847\n    1288030402577558570230666231\n\n");
   delete ae;

   ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'-');
   BigIntegerArithmetic bia2(ae);
   bia2.setUp();
   bia2.add();
   REQUIRE(bia2.showResults()== "     364287463834623846283426384\n    -923742938742934723947239847\n    -1288030402577558570230666231\n\n");
   delete ae;

   ae = new ArithmeticExpression("200","100",'+');
   BigIntegerArithmetic bia1(ae);
   REQUIRE(bia1.op1IsBigger(ae->getOp1()->getValue(),ae->getOp2()->getValue()) == true);
   delete ae;

   ae = new ArithmeticExpression("100","200",'+');
   BigIntegerArithmetic bia3(ae);
   REQUIRE(bia3.op1IsBigger(ae->getOp1()->getValue(),ae->getOp2()->getValue()) == false);
   delete ae;


   ae = new ArithmeticExpression("200","200",'+');
   BigIntegerArithmetic bia4(ae);
   REQUIRE(bia4.op1IsBigger(ae->getOp1()->getValue(),ae->getOp2()->getValue()) == true);
   delete ae;


   ae = new ArithmeticExpression("2000","100",'+');
   BigIntegerArithmetic bia5(ae);
   REQUIRE(bia5.op1IsBigger(ae->getOp1()->getValue(),ae->getOp2()->getValue()) == true);
   delete ae;


   ae = new ArithmeticExpression("200","1000",'+');
   BigIntegerArithmetic bia6(ae);
   REQUIRE(bia6.op1IsBigger(ae->getOp1()->getValue(),ae->getOp2()->getValue()) == false);
   delete ae;


   ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'+');
   BigIntegerArithmetic bia7(ae);
   bia7.setUp();
   bia7.add();
   REQUIRE(bia7.showResults()== "     364287463834623846283426384\n    +923742938742934723947239847\n    1288030402577558570230666231\n\n");
   delete ae;


   ae = new ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'-');
   BigIntegerArithmetic bia8(ae);
   bia8.setUp();
   bia8.add();
   REQUIRE(bia8.showResults()== "     364287463834623846283426384\n    -923742938742934723947239847\n    -1288030402577558570230666231\n\n");
   delete ae;
}

*/

TEST_CASE("class ExpressionReader")
{
  //std::ostringstream oss;
  ExpressionReader er("expressions.txt");
  //er.readExpressions("expressions.txt");
  //oss << er;
 //REQUIRE(er.toString() == "12 + 5\n5 + 12\n12 - 5\n5 - 12\n364287463834623846283426384 + 923742938742934723947239847\n364287463834623846283426384 - 923742938742934723947239847\n");

}



