  module top(
    input logic clk_i, rst_ni,
    input logic nickle_i,
    input logic dime_i,
    input logic quarter_i,
  
    output logic soda_o,
    output logic [2:0] change_o
  );

vendingMachine dut(.*);

endmodule: top
