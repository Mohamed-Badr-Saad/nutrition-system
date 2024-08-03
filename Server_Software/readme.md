##to build the server and run it you should use the following commands:

```bash
g++ -std=c++17 -o nutrition_server     main.cpp DataInit.cpp FileUtils.cpp FoodCategory.cpp FoodItem.cpp message_handler.cpp Patient.cpp DietPlan.cpp Disease.cpp     -lpistache -lboost_system -ljsoncpp
```
```bash
./nutrition_server
```
