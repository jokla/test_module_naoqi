#include <string> 
#include <vector>

#include <qi/anyobject.hpp>
#include <qi/applicationsession.hpp>


class MyService
{

private:
  qi::SessionPtr _session;

public:
  MyService(qi::SessionPtr session);

  std::vector<float> getJointValues (std::vector<std::string> jointNames) const;
  void sayHelloWord() const;

};
QI_REGISTER_OBJECT(MyService, getJointValues, sayHelloWord );
