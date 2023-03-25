#define MAX_SIM 200

void set_random(Vtop *dut, vluint64_t sim_unit) {
  dut->rst_ni = (sim_unit > 4) && (rand()%30 != 0);
  dut->nickel_i = rand()%2;
  if (!dut->nickel_i){
    dut->dime_i = rand()%2;
      if (!dut->dime_i){
        dut->quarter_i = rand()%2;
      }
      else{
        dut->quarter_i = 0;
      }
  }
  else {
    dut->dime_i = 0;
    dut->quarter_i = 0;
  }
}
