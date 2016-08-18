#include <myservice.hpp>

int main(int argc, char** argv)
{
  qi::ApplicationSession app(argc, argv);
  app.start();

  qi::SessionPtr session = app.session();
  session->registerService("myservice", qi::AnyObject(boost::make_shared<MyService>(session)));

  app.run();
}
