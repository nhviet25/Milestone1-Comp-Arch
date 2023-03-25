module vendingMachine(
  input logic clk_i, rst_ni,
  input logic nickel_i,
  input logic dime_i,
  input logic quarter_i,

  output logic soda_o,
  output logic [2:0] change_o
); 

typedef enum logic [2:0] {
  IDLE,
  FIVE,
  TEN,
  FIFTEEN,
  TWENTY
} state_e;

state_e state, next_state;
logic [2:0] coin;

  assign coin = {quarter_i, dime_i, nickel_i};

always @(state or coin) begin
  case(state)
    IDLE: begin
      case(coin)
        3'b001: next_state = FIVE;
        3'b010: next_state = TEN;
        3'b100: next_state = TWENTY; //change = 001, soda = 1
        default: next_state = IDLE;
      endcase
    end

    
    FIVE: begin
      case(coin)
        3'b001: next_state = TEN;
        3'b010: next_state = FIFTEEN;
        3'b100: next_state = TWENTY; //change = 010, soda = 1
        default: next_state = FIVE;
      endcase
    end


    TEN: begin
      case(coin)
        3'b001: next_state = FIFTEEN;
        3'b010: next_state = TWENTY; //change = 000, soda = 1 
        3'b100: next_state = TWENTY; //change = 011, soda = 1
        default: next_state = TEN;
      endcase
    end

    FIFTEEN: begin
      case(coin)
        3'b001: next_state = TWENTY; //change = 000, soda = 1      
        3'b010: next_state = TWENTY; //change = 001, soda = 1
        3'b100: next_state = TWENTY; //change = 100, soda = 1
        default: next_state = FIFTEEN;
      endcase
    end


    TWENTY: begin
      next_state = IDLE;
    end

    default: next_state = IDLE;
  endcase
end

always_ff @(posedge clk_i) begin
  if(!rst_ni) begin
    state <= IDLE;
    soda_o <= 1'b0;
    change_o <= 3'b000; 
  end
  else begin
    state <= next_state;
  end

  case (state)
    IDLE: begin
      soda_o <= 1'b0;
      change_o <= 3'b000;
    end

    FIVE: begin
      if (coin == 3'b100) begin
        soda_o <= 1'b1;
        change_o <= 3'b010;
      end
      else begin
        soda_o <= 1'b0;
        change_o <= 3'b000;
      end
    end

    TEN: begin
      if (coin == 3'b010) begin
        soda_o <= 1'b1;
        change_o <= 3'b000;
      end
      else if (coin == 3'b100) begin
        soda_o <= 1'b1;
        change_o <= 3'b011;
      end
      else begin
        soda_o <= 1'b0;
        change_o <= 3'b000;
      end
    end


    FIFTEEN: begin
      if (coin == 3'b001) begin
        soda_o <= 1'b1;
        change_o <= 3'b000;
      end
      else if (coin == 3'b010) begin
        soda_o <= 1'b1;
        change_o <= 3'b001;
      end
      else if (coin == 3'b100) begin
        soda_o <= 1'b1;
        change_o <= 3'b100;
      end
      else begin
        soda_o <= 1'b0;
        change_o <= 3'b000;
      end
    end


    TWENTY: begin
      soda_o <= 1'b0;
      change_o <= 3'b000;      
    end

    default: state <= IDLE;
  endcase
end

endmodule: vendingMachine
