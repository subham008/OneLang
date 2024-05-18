
#ifndef _FOR_LOOP_DATA_
#define _FOR_LOOP_DATA_
  


   class ForLoopData
  {
  private:
   std::string cond;
   std::string loop_d;
  public:
    ForLoopData(std::string condition , std::string inside_loop_data){
        cond=condition;
        loop_d = inside_loop_data;
    }


   std::string getConditions(){
    return cond;
   }

   std::string getLoopData(){
    return loop_d;
   }

    
  };
  

#endif