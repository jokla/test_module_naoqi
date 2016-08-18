#include <iostream>
#include <sstream> 
#include <myservice.hpp>


MyService::MyService(qi::SessionPtr session)
  : _session(session)
{

}


void MyService::sayHelloWord() const
{

  std::cout << "Function sayHelloWord Called" << std::endl;

  qi::AnyObject tts = _session->service("ALTextToSpeech");
  tts.call<void>("say", "Hello world!");

}

std::vector<float> MyService::getJointValues (std::vector<std::string> jointNames) const
{
  std::cout << "Function getJointValues called" << std::endl;

  qi::AnyObject tts = _session->service("ALMotion");
  return tts.call<std::vector<float> >("getAngles", jointNames, 1 );

}
