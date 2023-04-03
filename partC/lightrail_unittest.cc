#include "gtest/gtest.h"

#include "app.h"
#include "driverfactory.h"
#include "passengerfactory.h"
#include "lightrailfactory.h"
#include "stationfactory.h"

#include "lightrail.h"
#include "passenger.h"
#include "driver.h"
#include "station.h"

class LightRailTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
    
  }
  void TearDown() {

  }
 protected:

};

TEST_F(LightRailTest, test1) {
  
}

/**
 * You can create other test classes if you would like
*/

int main(int argc, char* argv[]) {
  int pid = ::getpid();
  std::cout << pid << std::endl;

  for(auto& s : std::vector<char*>(argv, argv + argc)) {
    std::cout << s << std::endl;
  }

  std::string current_exec_name = argv[0];
  if (current_exec_name != "./out/lightrail_unittest_correct") {
    throw std::runtime_error("Į̶̧̢̨̡̨̧̨̨̡̧̧̨̢̡̡̨̛̛̛̻̤̟̠͍̥͎̳̮̫̪͎̜̹͔̫̱̘̼̺̝͔̯̰̤̟̝̗͕̥͇̞̻̙̥͔̞̘̣͔̰͚̙̗̮̪̩̬̭̖̣̟̤͇͉̯͚̹̫̭͍͓̺̞͍̞̺̗͇̣̗̬̩̲͓̙̥̙̖̦̩̞͎͓̞̝̤̟̝͎̝͚̝̫͉̘̩̞̰̜̙̗̮͉͍͚͇̖̼̩̤͓̩͕̮̰̦͈͔̘̯͔̮̯͓̬͎̝̫̬͈̭̭̯͎̭͍̝̪̮̦̠̻͚͍̺̫̲̥̬̹̹̖͍̼͓̫̫̗̯͓̩̔̈́̿̾̓͛̃͋̂́̍̄̇̀̿̓͗̇̎̽̆́͋̋͒̓͊̊́̈́̈́̍͑͗̎͐̎̿͂͂͑̏̽̈́̏̊̔̃͒̽̿̑̇̊̐̎̉̔͐̂̎̎͌͋̀́̀́̈̽̎̓̋̀̓̋͒͛̔͒̈̔́̿̓̊͌̄̅͐̏̋̈́̂̇̇̄̋̀̽͋͐̉͛̀̑̄̄̂̀̓̃͌͊͂̌͗̇̍̽̓̀͐̈́̑̈́̀͆͑͊̈́̎̃̔̈́̄͌͛̎͆̎̔̈́̾͋̎̽̓͋́̔̈͛͗͋͌̔͆̄̔̔̈́̈́̎̄͂̍́̈́̀́̑̔́̊̇̇̈͗̉́̋̽̎̐̏͘̚͘̕͘̚͘̚̚͘̕͘̚͘̚͜͜͜͜͝͝͝͝͝͠͝͝͝͝͝͝͝͝ͅͅͅͅͅͅͅͅ'̵̡̡̢̧̦̥̯̝̣͔͎̠̳̹̲̪̰̺̼͚̥͖̝̤̱̺̜͕̞̪͕͉̞͍͚̦̻̤̳̞̲̞̮̱̯̜̬͙̝͉͉͎̭͖̙̫̪͎͛̂̈̇̒̃̎̈́̌̔̔̿̾̋̀̆̐͊̀͗̕̚̕̚̕͜͠͝m̷̡̛̛̛̗̙̹̞͚̝̣͓͚̍̿̌̒̃̃̒̽͋͒̃͐̉̅̈́̔͐́̉̓͌͗̃͋̾̀̃̾́̔͐͆̊͌͆̎̐̉̂̀͐̿͛̃͋̈́̈́̑́͊̓́͊͊͂̂͒̈͗̃̊̀̆̔͗̑̉̏͋̀̃̉͗̏̓̂̏̓̇̈́̀̏̌̔͐͗̊͒͒̍͌̍̈̎̽̽̇̎͋̈̾̇̃̀͂́̽̋̅̐͌͐͑̏̒͛͒̉̓̄̌̽͛̇͋̍̈́͛͐͊͊̾̅̋̒̈̂́̄̀̑̊̈̿́̐͂̑͗̈́̉̑͐̔͒̐́̽͗̄̀̾̂͐͛̚̚̕͘̚͘̕͘̚͘̚̕͝͝͝͝͠͝͝͠͝͠͠͝͝͝͠ ̵̧̧̡̡̧̢̡̧̨̨̧̡̧̧̧̧̛̛̩̬̩̩͍̙͉̻̬̞͎͈͙͓̦͎͔̘̯̥̝̭͚̬͕̦̭̣̹͖͕̤͚̻͚͕̤̪̳͓͔̣̙̞̱̞̞͔͙̬͖̖̺͉͍͇̠̰̘̝̠͙̤̙̰̙̦͚̲͙̖̠̥̣͇̬̲̠̦͕̭̬͔̞̤̜͔̤̝̝͔̳̙̻͕̥̳̭̼̦̖̠̗̞̼͙͙̦̮̞̝͖̖̙͎̫͚̱͖͕̮̗̦̻̭̥̝̬̻̠̘̙̮͕̬͓̖͖̰̹͇͕̦̠̹̭̙͕̘͎̲̥͕͚͖͍̤͕̩̤͉̱̥̞̤̱̲͓̤̣̙̥͖̭͔̼̗͖͙̝̙̳̟̫̘̖̺͉̞̤͇͍͈̻̬̯̝͔̦̥̣͓͉̙̾̋̈́̄̎͑͒̾̂͊̅̾̀͒͑̒̊̔͊́̄̎̈́̋̅́͊̏̓̽̾͌͛̃͂̌̌̂̀̊̾̓̀̐͐̽̉͑̇̊͂̇͋̈́̀͌̈́̚̕̕̚͜͜͜͜͜͜͝͝͠͝ͅͅͅͅͅͅͅą̵̨̛̛̻̠̮͍̖̩̞̰̬̲̱̪͍͈͍̳͇̩̞̹̳̬̣͖͓͔̯͎̏͑̅̓͋̄͌̍̏̏̐͆̈́̎̔̈́̉̉̏̋̿̽̎̇̌̿͌̀̎̚͘̕͜͜͝͝͠͠͝ͅ ̴̨̢̢̡̡̢̡̧̛̛̛̳̩̠̬͈̰̯̲̤͈̝̺͔͓̠͉̟̝̪̪̱͎̪̞͙̖͎̻̱͙͔̰͇̲̲̺̙͙̞̥͚͙̙̤͔̘͚̺̝̤̘̲̞̦̞̺̭̩̣̥̹̱̭̣̫̹̭͙̼͇̯̥͕͔̩͇͓̮̗͚̦̫̦͙̟̮̟͚̤̖͔͖̖̲̺̠̪̜̙͙̰̣̖̹̅͊͗̈́̽̈́̌̽̍̏̔̋̊̌̉̍̇̒͋͆̇́̇̈́̀͛̾̀̽̐̃̽͆̀̿̃̊̈̆̊̓̀̿͒̽̔̐̏͂́̈͌̎̃̓́̌̃̓̈́̂̈́̿̍̅͆̒͛͂̎̄͑̽̎̀͛̓̓̔͗̋̓̈́̀̾̑͑̈̿̊̉̉̓͗̾̾̂̐̅̑̇̈́͒͌̈̈́̍̉̾͊̋͑̀̿̇̏̍̔̾̾́̐͗̂̈́͗̅̀͑́͊̋̾͐̒̍̐̌̅̂̒̀̀̔͐̾͋̋̾͋͊͋͋̋͋͛͐̇͊́̇̍̉́̾͊͊̂̈́̏̅̆͊̉͑͌̀̈́̂́͒̔̈́̽̉͐̒͗̍̀̽̀̈̄̀̇͂̃̈́̎͑͌̕̕͘͘̚̚͘̕̕̕͘̚̕͘̕̚̕̕͜͜͝͝͝͠͝͠͝͠͝͝͠͝͝͝͝ͅͅͅm̵̧̡̨̧̡̡̨̛̛̛̛̟̬͇͖̰͇͖̣͕̠̦̗͎̼͍̩͚̦̯̝̲̱̺͎͉̙̩̰̰̮̣̤̘͕̯̺͓͎̣̪͔͔̦̺̬̩͕̻͚̣̪̺͔͓̗͚̬̝̦̺̙̞̻̣̭̫̱̥͙͔̦̱̲̜̩̳͉͙͇͂̊̾͂̂̏͛̀́̀̆̋̓͐̉͗̿̔͗̈́̆͐̈͒͆͗͊́̑̆̅̿̒̒̈́̈́͌̔̇͛͊̈́͆̈́̿̃̎̇́̽͗̓̓͑̀̂͒̋́̾̓̒̆̈̾̽́̍̉͂̈́̈́͛̓͒̽̏̈́͂̒̽͒́̆̂͌͗̈́̑̽̇̎̑̿̍́̔̃͋͛̀͗́͛̎̀̍̔̈́̓͂͗͐́̅̔̑͒̀͊͌͌̊͒̋̋̎̏̓̃̀̍̒͋̓̂̋̂͗̃̀͆͂̒̊͂̍͂̿̈́̎̌͆̌̾̍́̽̇͘͘̕̚̚͘͘͘͘͘̚̚̚͘̕͘̚͜͜͜͝͝͠͝͠͝͠͝ͅͅǔ̴̢̡̨̧̢̡̢̨̡̧̨̧̧̢̨̡̢̡̧̧̢̢̨̢̡͙̗͓͈͖̮̥̮͈͇̫̖̲͙͕̙̜̯̳̥̲̼̭̯̟͈͕̯̼̥̟̫̳̟͇̣̝͚̹̫̫͓̼̻͔̯̭̺̹̬͔̹̭̘̞͔̫̳̲̼͙̫͓͙̼̘̙̹̩̱̭̲͚͖̭͔̼̙̯͚̜̰̥̖̞̬̖̜̮͈͇͈͖̻̘̲̩͎̣̥̠̩̳͇̩̜͔̞̼̝͕͔͕͇͓̖̩͎̯̜̙̞̠̹͖̼̫̠͔̭͔̰̼̞̖̖͚͈̩̪͓̪͎̩͇̰̲̦͈̻͎̗̩͇̯̪̝̤̩̪̺̜͍̼̙̭͕̺̱̹̳̬̬̱̟̩̦̣͚̳̙͓̠̥̜̼̖̜̹͈̻͔̘̦̜̫̘̬̲̖̠͕͕̫̮̹̪̺̞͉̘͚̬̮͎̦̝̟͇͎̘̼͈̲̥̺̥̲̗̱̫̫̝̙̟̺̖̙͓̭̹̹͋͜͜͜͜ͅt̶̢̧̡̡̧̨̨̡̢̨̢̡͓͎̣̹̻̰̦̠̱̮͈̦͈̜̥̠̣̮̩̩̣̞̰͓̪̪͙̝͓̬̼̖̺̪͓̰̣͍̭̣͕̳͖̝̹͔̗̲̟̱̜͙̥̞̫̪̭͚̳̻̜̦̘͙̮̥͔̲͓͈̩̣̠̜̞̗̪̭̝͈̜͙̣͈̻̥͍̼͔͙̞̲̖̦̱̗͉̹̘̰̼͖̣̝̘̾̓͑̀́̍̒͋̔̑̐̒͛̾̆̒̓̓́͆̽̇̈́̓͗̉̐̇̈́̐̑͐́́͋̓͗̌̃͗̓̑͂́̋̀͗̐̓̄̅̓͒͐̈́͒̏̐̃̕͜͜͜͜͠ͅḁ̶̛̰̭̦͓͙͉̩̹͓͙͚̯̹͇̟̮̘̫͇̟͒̓͑̋̈́͒̃̓͐͒͑̍͆͑̎̃́̐͋́̈́͌͊̈́̓͒̑̓͊̽͒̏̒̎̏̎̂̑̈́̌̉̍͊̃̈́̆̒̓̑̄͛̈͒͒͂̒̈͆̐́̓̄̏̆̀͊̊̈́̋̇̓̓͘͘̕̚̚̕̚͠͝͠͠ͅͅn̴̡̧̧̢̢̨̧̢̨̡̡̢̡̧̨̡̢̛͎̬̺̤͚̙͈̰̠͇̖̼̱̰̼̠̗͇͎̻̠͉̱̮̝̘͉͚̭̜̻̖̰̤͓̱͕̫̣̪̙̲͉̦̮̬̲̼̩̭̰̻̰͚͔̙͎͍̼̘̰̟̝̗̮͈͎̬͍̭͎̦̞̣̗̯̳̹̥͉̱̯͈̬̘̬͓͈̼͉̠̙̙͚̣̠̗̤̟̪̣̪͕̞͓̟̞̩͇͚̠̻̳͇͎͙͚̟̜͈̻̦̣̭̻̬̟͖͓̠̘͈͎̤̤̗͙͓͈̖̟̫͎̟̩̮͔͓̹̬̬̗̻͚̗̪̝̜̟̰̼̳͔͎͚͍̫̘̥͇̦͓͚̖͉̙̮͍̰̯͊̀̐̒̐̆̀̓͒̎̎͌̎̄̓̈́̾͑͗̌͂̂̑͛̈̊̀̐̽̊̊̈̾́́͐̇̇̃̋̿̐̓̌̆̋͑̆̈̌̊́̈́̍͗̂̐̀̾̉͒́̓́͆͐̈͆͋̿͌̋̍̒̑̇̓̍̈́̐̈͆̐͑̎̐̉͑̌͂͘̕͘̚͘̚͘͜͜͜͜͝͝͠͠͝ͅͅͅt̷̨̨̢̨̢̢̨̢̧̧̢̡̧̨̡̛̛̛̛͙͖̦̖̮̜̠̹̰͖͇̯̘̹̗̝͙͇͇̲̗͎̰͖̲̭͔̹̲͙̘͖̠͙̯̰̰̩̱̳̱̝̦̯̠͎̠͎̲̝̫͈̗̬͚̻͕̬̲̯̰̺̳̝͙̜̮͇͔̝̠̣̘͉̭̹̼͔̠̗̬͙̣̳̬̮̖̥̩̺̬̪͓͔̪̟̐͒̍̊̐̎̇̌̎̈́̈͋̓̒̉̒̀̽̐͆̐̇̅̆̓͋̄̇̒̔̄͒̾̎̈́̇͛̈͆̃̈͑͑̊͌̿̔̅̈̋̍̍́̎͛͗́̍͑̇͆̌̀́́́̈́̄͛̉̎̇̉͊̀̏͑̈́̋̅̌̑̒͛͐̀̔̂̓̿̽͐̄̈͑̈́̒̌͒̾́͊̀̍̅͗̃̾͐͒̑͂̌̇́̌̏̃͒̎͑̐̄͑̒̈́̈̿͊̌̈́͗͊̀́͒̋͒̏̋͊̈̀͗̓̒͌̇͑̊͒̈́̾̈͋̑̈̉͑̒͂͂̌͑͛̉̆̆̒̈́̾̆̀͒̌̇͊̂̏͆͐̾͛̊̇͐͋̌̎̌́̓͛͒͊̓́͊̊͌̌̔̍͒̌̊̾͐̒̂̊̇͂͛̈̈́̓̉̉̓̆́͑̔̒̈́͗̑̒̔̂͑͗̈́̔̔̔͘̕̚͘͘̕̕̚̕̚̚̕͘̚̚̚͜͜͜͜͝͠͝͝͠͝͝͠͠͝͠͠͠͝͠͝͝͝͠͝ͅͅͅ,̴̡̧̨̧̢̨̡̢̡̢̢̡̛̛̛̛̛̛̛̝̼̝͓̖̦͓̳̜̻̞͖̯͕̹̟̥͓͈̙̱̟̟͙͓͕͈̺͔̱̥̜̜̼͉̬̥͚̘̺̬̜̫̝̻̼͉̘̳̥̙͎̥͍͉͔̰̰̬͙̬̳͎͖͕̬̯̪̪̤̙͙͖͕̱̳͖̬̺͕͙͎̜̘̳̭͔͖̜͇̯͔̝̰͉̥͔̤̭͉̩̺̻̥̜͉͙̤̗̼̬̦̼̠͍̮̜̫̲̪̘̻͓̻̼̥͙̠̘̮̟̯̘̜̰̭̳̠͖͉̬̹͇̣̬͙̦̰͚̠͉̪̬̠̠̤͉͍̣͓̲̫̜̰̝̲̠͇̖̳̙̝̭͓͓̹̜͉͇͔̞͈̝̯͎͍̩̭̝̥̎̏̏̓͐̽̐͆́̽̊͊̓̀̍́̑̇͊̀̃̐̅̾̐̾̍̑́͋͂̎̉̎̂́͗̊̅̑̂̾̽͂̇̎̋̈́̑̑͋̏̍͗͗͋́̈́̍͊͌̓͆͌̄̈́̓͐̍͋̅̈́͛̌͂̈̓̆͒̎̋́̈́̂̀̾̽̔̏͑̽̈̈͆̔͋̑̑̿̉͑͗͑̊̑̉͐̀̔̑̍͛̑̈́̌̈́̚̕̕̚͘̕͘͜͜͜͜͜͜͜͝͝͝͝ͅͅͅͅ ̴̨̢̡̡̡̨̨̛̛̛̣̙͔̣̮͈̘̲̗͇̠̻̰̘̭̙̜̠̦̪̝͓̟̱̺͉̩͇̺̮̭̮̥̫̭̻̲͇̜̩̻̭͉͚̯͕̩̝̟̠͓̪̯͙̟̟̺̱̯̝̺͈̩̙̞̺̱͇͎̜̬̘̥͍̩͔̗̲͉͙̘͇̣͈̭͉͌̿̈́̿͂͛̿͂̽́̆̆̀̋̎̔͜͜͝͠ͅͅͅͅk̴̡̢̡̨̡̡̧̧̨̧̨̛͖͙̥͔̳̲̩̼̠̣̩̻̣̱͔͓̹͉͙̰͕̫͚͔̟̺̝̦̰̪͓͚̹̮͙̮̤̞̰̞͙̖͙̠̥̼͙̙͙̻̮̭̺̝͙̭̲̥̤̪̱̹̟̗͉̰͇̟̻̮͓̘̝̼̭̭̱͍̺̖̬̹̖̥͚̝̙͚͔̺͇͖͓̹͚͙̗̼̖͔͉͇̻̣͙̣̫̼͙̣͉̥͙̙̖̗͉͎̙̳̖̳̻͔̰̘͕͓͎̼͈̟͚̲̝̣͙̙̠̱̖͓͚̖̺̗̞̜̬͖̺̫̪̺͓̜̼̬̱̣̤͚̩̗͍͓̺̭̣̹̺̭̍̈́͌̽̔̄̓͊̓̋͑̓͆̔̓̋͂̈́̔̿́̃̏̈́́̂̀́̒̽̄͂̔͗͊̽̆̀̾̃̋̐̈̍̎̋̿͑̈́͆͊̊̓̏̓͊̀̌̀̑͂͒̂̓̆̒̓͂̔̃̆̓̋̐͆͆̇̐͗̔̑̍̈́̑͊́͊̈́̓̋̃̀̏͐̉́̎̐̃̀̇͑̈́̈̆̍͋̋̓̏̏̊̆̅̃͒̈́́̍͗́̓͋̀̓̅͐̈̊̅̔̅̓̆͂͑̈͌̓̉̔̇̍͆̅̎̐̊͐̌͗̔͒͒͌́̎̈̄̂̿́͑̾̃͊̓̀͗̐̓̽̄̿̄̌͗̃͐̎͒̄̈́͆̓̉͌͂̽̄̾̊̂̓̓̍̏̐̔͆̈́͛̀̚͘͘̚̚̚̚̚̕͘̚̚͜͜͝͝͝͠͝͝͝͝͝͠͝͝͝͝͝͝ͅͅͅͅͅͅị̵̧̨̡̡̢̧̡̡̧̢̛̛̛̛̛̛̛̲̬̙̬̲̪̞̥̗̱̞̜̹͍͕̫͕̭̥̻̥͖͍̙̠͚͈̮̣̩̖̬̣̳͕̣̻͍͍̖̣̖͇͓͖̤͖̗͖̺̲̜͉͙͚͈͓͉̬͓̱͕̲͍͎͕͔͕̗͚͈̯̝̖͇̟͇̜͉̞̳͈̻̯̳̈̉̃̈̄́̔̆̉̽̈́̂͑̌̏̓̆̇̉͆͋͋̾̉̓̀͗̑̈́̀͌͛͗̑͋̈́̈̐͒̑͛̈́̔͗͗̆̔̇́͂͐̀̊̋͐́̐͊̊̓͌̒̀̃̀̄̿͆̍͑̽̀̿̓͐͛͋̀͆͂̉͗͐͂̂̑̅̑̄̎̍̇̂͛̂͊͒̿̇̊̋̋́̿̄͛̅͂̅͆̽̿͋̈́̆̋̿̀͛̔͋̍̈́̾̽̑̊̀͛͌̉́͑̀͂̈́̓̈́͐̈́̐̿͑̓̎̓̽͐̈̏̐͑̽̓͗͆̎̌͊̿̈́͗̈́̊̓̍̎̇̿̔̀̌́͋̆̓̊͗̆̈́̿̆͐̈́̀̈́̾͒̏̋̓̈́̆̆̀̑̾̓̏̔̋́̏͐̀̈́͌̋̆̊̾̍̓͂͂͐͐͐̀͗̇̚͘̚͘̚̕̚͘̚͘͘͘̚͘͘̕̚̕̕̚̚̚͜͜͜͜͠͠͠͠͝͠͝͝͝͝͝͠͠͠͠͝͝͝͝ͅľ̷̡̢̨̢̡̧̧̨̨̧̧̛̛̛̛̛̪̭̙̟̬̤̪͇̪͓̦̞͎̙̙͇̝̺͇̮̩̫̖̹̦̤̜̤̜̗̲͔̝̙̠̺̹̠̙̘̠̺̬̻̻͔̘͎͉̯̳͔̜̤͙̘̘̺̪̲͚̹̻̳̣̗̝̦͔̦̰͔̥̼͙̮̼̗̯̖̌́̑̑͌͑͛̄̔̌̀̂̈̇͊́̀͐̔̆̽́̋̿̈̍̊̋́͛̔͋̌̔̄̅̋͂͑̓̒͛̃̉͌͒̏͒̊͊́͛̐́́͗͗͆̅̇̔͗̽̊̀͒̓̍̍̀̄͂͆̑͆̂͑̄̋̒͐̌́̑́͋̄̀̏̓͐̐͌͒̀́̕̕͘͘͘̚͘͜͜͝͠͝͝͝͝l̵̢̡̧̧̨̧̡̧̧̡̢̡̢̨̢̡̨̢̨̡̛̛̛̖͕̰̻͕͇̫̣̣̖̤͚̞̩̺̦͇̘̩̺̼̯͍̝̙͖̳͕̭͖̣̞̮̣͖̤̙̳̳̱̞̖̪̝͈͚̤̯̹̼͇̻̪̱̜̖̖̠͔̙̤̣̙̹̬̥̱̳̹̮̲̦͖̠̖͚̳̗͕̠̬̼͕̥̣͉̞͕̬͙͕͓̰̫̗̯̞̻͖͓͓̰͍͉͔̼͚͍̳̗̞̞͎͎̩̝̮͔͙̤̮͖̭̯̣̣̠̠̗̰͕̣̘͕̜̘̼͎̹̝̗͍͎͖͉̯̖͍͉̬͔̪͔̬͖̘̖̞̰̰̩͈̗̳̣̰̞͍̜̰̠̭̳̬̖̮̟̣̻͙͔̰̜̩̠̩͎̥̜̜̣̼͇̜͙̦̻̹̤̯̯̼̗̞̯͕̝̦̭̪̬̲̮͖͚̠̻̪͇̮̩͔̬̼̳͚̟̭͈̤̫̻͚̳͍̬̙̘̦͖̜͉͎̣̹̙̼̤̠͍͉͓̹͉̤͕̮̮̦̟̘̬̱͉͇͖̣̇̊̐͂̐̑̑̍̊̏̑̈́̀̀͌̆̅̍͌͋̓͂̃̃͒̀͆͆́̉͛̓͛̓̓͑̍͗̆̈́̆̀̑́̇͗͋́̊̊͗̑́̾̋̑͗͌͂͑́́̈́̀̅̏͒̾̂̀̾͗̀̏̂̌̑̓̓̓̏̄̅̄̐̈́̂̃̔̈́͒̔̀́̐̄͋́̏̆̽̑͊̾̆̒̂́͛̊̏͋̆̉̅̅͗̇̏̉̏̿̊͛͗̈͊̆̒̊̄͐̄̓̋͑̋̒̎͋̔͆̐̽̏̀͆̔̒̄̀̇̄̈́̆͗̓̎͋̏̍͋̏̈́̎͊̓͛̈́͛̾͑̆͊̌̿̒̽̿́̇̀̇̓͊̀̆̀̂̄̄̈́̀̆͗̄́͒̅̓͑̆̈́̉͛̈́̏͗̚̚̚̚̚̕̚͘̚̚̚̚̕͘̚͜͜͜͜͜͜͝͝͠͠͝͠͝͝͝͠͝͝͠͝͝͠͝͝ͅͅͅͅͅ ̴̨̧̡̨̧̢̢̨̢̡̨̢̨̛̛͎̫̼͈̥̱̩̙̙͓̣͕̞͙̬̪͎̩͈̞͔̮̱̖̙̮͈̗̹̹̦̤͚̠͎̞͓̥͚͍̰̹͎̰̬̻̺͎̺̲̪̻͎̖̤̳̟͔͎̺̩͓̪̤͕̺̦͕̝̺͈̮̬̝̳̱̩͉͚͎̥͍̪͙̥͎̳͙̲̝̙̥̫͉͙͈̭̳͈̠̮̹̝̦̭͕̖͔͙̫͎̖͕͉̞̠̦̬͎͚̭͍̝̆̈̉͒̄̋̈̋̂̽̀̅͑̒͊́̔̈́̋́̄͛͛͂̆̎͋͂͒͑͗̈́͌͛͆͒͋͂͗̇̈́̈́̈̏͋̈̆́̆̏͛̉͑̂͒̄̃̾͌̊̾͋̾͗̄̎̔̅̈́̓̓͌̏̑̑̀͑͗̾̃͑͐͛̿̿͊͑̕̕̚͘̕͘̕̕̕͜͜͠͝͠͠͝͠͝͝ͅm̴̨̧̢̧̢̡̢̧̢̢̛̛̖͉̥̞̺̞͈̣̘̮̫̪̟͙̤̞̫̘̲͉̗̦̻̳̲͉̭̯͍̙̦̱͇͉̟̥̬̘̝̲͔̘͙̖̮̬͙̘͓͓̰̮̤̖̞͚̯̲̣̪̘̺̦̙̙̤̜͕͔̳͍̭̣̯̞̫̹̟̞̳̰̫͊̀̉̋̑͊͌̀̈́͑̐͐̔͂͊̒̍́͋̐́̋̂̆̈͋̒́̓̀̄̐͑̑̊̔̿͗̄̊̉̆̌̂͐͐̔̀͐̏̾̒̀̌̌̈́̔̔͋͊̑̿̇̀̎͋̈́̑̃̋̀̑̊̌̅͘̕̕͘͘͜͜͝͠͝͝͝ͅͅͅͅe̶̡̨̨̧̛̲͇̟̣̙̰̝̺͍͍̖̰̜͉̮͍̩̭̳̗̼̱̱̞̣͉͙̰̹̯͈̤̯̹̣̭͖̭͍̠̻̯̟͎͓̰̺̹̹̺͈̪̤͍͚̝̫̞͈̖͍̰͕̝̜̹͎̤͍̺̤͐̈́̋̈́̈̈́̎̄̒͐̒͆͐͒̓͗̓̓̑̍̐̏̾̆̒͋̆͒̆͐̌̈́̅͂͗͑̂͛̄̈́̈́̄̈́̎̓̈̔͌̇̐̾̍̑͆̇͛̐̔̏̄̓̑̂̆̾̆̌͊̿̇̑̓͊́̌́̄̏̒̄̚̚̕͘̚̕͠͠͝͠͠͝͝͠ͅͅͅͅ ̷̧̨̢̛̛̛̛̛̛̛͇̯̼͙̜̲̙̩̞̜̼̳̙̮̮̪̖̙͚̮͚̘̘̗̈͋͋͌̇̓͗̆̇̽̑͂̔̃̉͋͆̔̆͛̋͆͐͂̓̔̀̔͆͐̉̐͌͌̐̒́̊̍̅͋̿́̆͆̀̿̇̈́̔̌̾̿̓̏̄̊̃̆̇̀̊̀́̍̔̇̎͆́̅̅̎́̍̅́͐́́̓͒̊̆̈͂͐͗̃̀̎̏͆͐̋̓͛̓̽̄̃͌̊̆̔̆̍̋͐̔̐͗̄͊̑͂̌̒̄́̌̋̀͛̓̈́̃̑͛͋̍̈́̾̿̓̃̄́̈́̓͗̃̑̏͒͒̅̆͂̈́̂̋̈́̎́͐̌̋͒̒͒͗͋̀̒̒̌̓̒͆̊̂̇̿̿̏̌̃̎́̎̄̾̂̀͌̓͂͑̄̃́̔̀͋̄͊̀̃̒͑̀̿̂͑͑̋̓̽̂̏̐͆̒̒̑̓̌̓̎̆̿̓͊͗́̈̔̏̚̚͘̕̕͘̕͘͘̕͘̕̕̚̕͘̚͜͜͝͠͝͠͝͠͝͝͝͠͝͠͝͝͝͝͠͝͝͝͝͝͝͝ņ̴̡̨̧̨̢̢̧̡̢̨̡̨̧̧̨̢̧̡̧̨̢̧͇̳̹̳̞̯̥̬͍̳̖̮̟̪̲̘͓͓̪̬̱̭̗̩͙̟̰̮̯̳̯͔̺̫̞͙̳̞͔̘͍̼͙̦̠̫̘̪͖̲̗̬̣̩̭̻̖̼͎̤͈̝̱̗͇̖͈͔̲̱͚͕̮͚̱̱̙̤̗̝͙̳̖̪̱̤̪͓͙̼̥͍͔͇͈̦͙͇̤̲̺̯͍̞͍̪̳͍̤̱̺͓͎̤͕̭̖̥͉̞̣̻̳̺̥͎̤͓͓̻̹̝̼̝͓̠͓̣͇͇̱̙̲͚͎̺̯̠̼̗̹̬͚͚͚̺̫͈̞̗̻͖̘̲͎͖̖͓͎̖̠́̋͋̇̇̎̊͑̓̈̾͑͜͜ͅơ̶̧̡̡̨̼͈̼͖͎̘̳̘̰̣̱͔̹͍̟͉͓̰̖̻̗̣͎̭̤̣̫̟̺̫̤͖̘̪͈̜͍̞͕̤̞͈̊̉̀̇͒̀̈̃͒̓̑͂̐͂͗͑̒̈́̂̔͂͒͋́͌̽͑͊̅̊̄͆̒́̔̋͊̈́̋̈́̈͛͘̚͘̚͜͜͠͝͝͝ͅẅ̴̢̧̨̡̢̡̨̧̨̢̢̢̢̧̧̧̡̢̢̧̧̧̡̢̨̧̧̛̛̛̪̱̼͚͓̫̦̲̳̲̪̼͓͎̻͉̬͈͚̯͈̼̰̫̟̲͕̜͕͈̙̖̫̲̤̺̗̠͇̙̠̲͚͔͕̩̪̥̟͙̖͚̭̩̖̺͈̟̗̹̹̤̪̠̜̪̟̙̘͙̫̩̱̻̤̜̹̺͍̭̥̫͖͇̥̗̥͙͙̯͉̪̤̞͕̪̪͚̦̩̭̰̖̠̯̲̖̝̱̰̟̜͈̫͔̩̩̲̟̙̬̯̪͎̺̼̘̱͓̬̗̲̥̖̩͉̭̰͕̻̲͚͓̞̫̼̭̩̼̬̙̥̘̼͎̬̘̠̫̜̩̼͍͈͇͙̤͎̪̗̹͍̳̺̗̗̮̠̠̩̬̤͔̫͓͎̺̩̙̮̞͚̯͈̞͚͖͍̰̰̹͍͔̜̺̥̜̟̩̪͉͈̟̖͍̖͉͓͈̭̦͚̳̙̭̤͍̙̥̮͇͔̯̦̭̟̞̼̥̮̀́̀͌͂̀̓̾̐̐́̒̀̓͗̀̒̋̋̓͐̍̒͂̇͆̓̃͛̉͋̆̀͆̎̇̏́̀̃̈́̌̓͊̉̓́́̔́̇̒̔͊̆̀̇́̀̈́̈́̀̈́̄̈́͆͌͆͆̌̓̓́̽̒͑̒̽̽̓̎̿̍͑̎͌͊͒̈̑̂̓͂̀̃̉̉̐̉̂̒͑̓̅͋̿̆̌͆͗̉̎̅̃̄̂̋̈̍̎̎̾͆̑͆̌̏̀̓̐͆̀͘̚̚͘̕̚͘͘̕̚̕͜͜͜͜͜͝͝͠͝͠͝͠͝͝͠͝͠͠͠͝ͅͅͅ!̸̨̡̛̩̖̪̫̘̟̩̼͓̬̱͖͎̖̣̙͔͇̙̺̯͓̩̙͎͐̀̈́̆͑͗͛̌̉͗̈͂̈́̄̋̉̈́͒͑̀͂́͌͋̽̑͌́͂̆͌͊̆͗̉̿̾̇͂̿̀̽̄̌̈̾̏́̚̚̕̚̚̚͜͝͝͠͠");
  }

  return 0;
}
