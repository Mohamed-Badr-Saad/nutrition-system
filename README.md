# nutrition-system
The user should be able to submit his personal info, health history then receive a diet plan based on his data


to build the server and run it you should use the following command
   g++ -std=c++17 -o nutrition_server     main.cpp DataInit.cpp FileUtils.cpp FoodCategory.cpp FoodItem.cpp message_handler.cpp Patient.cpp DietPlan.cpp Disease.cpp     -lpistache -lboost_system -ljsoncpp
 ./nutrition_server

