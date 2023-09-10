module seq_gcd (
        clk,
        rst_n,
        load_i,
        a_i,
        b_i,
        gcd_o,
        done_o
);
        input wire clk;
        input wire rst_n;
        input wire load_i;
        input wire [31:0] a_i;
        input wire [31:0] b_i;
        output wire [31:0] gcd_o;
        output reg done_o;
        reg [31:0] a_q;
        reg [31:0] b_q;
        wire [31:0] a_muxed;
        wire [31:0] b_muxed;
        reg CS;
        reg NS;
        reg load_int;
        always @(posedge clk or negedge rst_n) begin : proc_seq
                if (~rst_n) begin
                        a_q <= 0;
                        b_q <= 0;
                end
                else begin
                        a_q <= a_muxed;
                        b_q <= b_muxed;
                end
        end
        assign gcd_o = a_q;
        assign a_muxed = (load_int ? a_i : b_q);
        assign b_muxed = (load_int ? b_i : a_q % b_q);
        always @(posedge clk or negedge rst_n) begin : proc_update_state
                if (~rst_n)
                        CS <= 1'd0;
                else
                        CS <= NS;
        end
        always @(*) begin : proc_compute_NS
                load_int = 1'b0;
                done_o = 1'b0;
                case (CS)
                        1'd0: begin
                                done_o = 1'b0;
                                load_int = load_i;
                                if (load_i)
                                        NS = 1'd1;
                                else
                                        NS = 1'd0;
                        end
                        1'd1: begin
                                load_int = 1'b0;
                                done_o = b_q == 0;
                                if (b_q == 0)
                                        NS = 1'd0;
                                else
                                        NS = 1'd1;
                        end
                endcase
        end
endmodule