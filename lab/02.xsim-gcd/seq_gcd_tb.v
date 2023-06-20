module seq_gcd_tb;
        reg clk;
        reg rst_n;
        reg [31:0] a;
        reg [31:0] b;
        wire [31:0] gcd;
        wire done;
        reg load;
        event done_event;
        wire [3:0] tb_count_out;
	reg [31:0] aa [0:4];
	reg [31:0] bb [0:4];
	reg [31:0] eexp_gcd [0:4];
	reg [7:0] i;
		
        seq_gcd DUT(
                .clk(clk),
                .rst_n(rst_n),
                .load_i(load),
                .a_i(a),
                .b_i(b),
                .gcd_o(gcd),
                .done_o(done)
        );

        reg [31:0] exp_gcd;
        
        initial begin
                $dumpfile("dump.vcd");
                $dumpvars(1, DUT);
        end

        initial begin		        
                clk = 1'b0;
                rst_n = 1'b1;
		load = 1'b0;
                a = 0;
                b = 0;                
                exp_gcd = 0;
				
		aa[0] = 32'h009D5972;        // 10312050
		bb[0] = 32'h01C18938;        // 29460792
		eexp_gcd[0] = 32'h0000008A;  // 138				
		aa[1] = 32'h76D457ED;        // 1993627629
		bb[1] = 32'h462DF78C;        // 1177417612
		eexp_gcd[1] = 32'h00000007;  // 7
		aa[2] = 32'h7CFDE9F9;        // 2097015289
		bb[2] = 32'hE33724C6;        // 3812041926
		eexp_gcd[2] = 32'h00000001;  // 1
		aa[3] = 32'h72AFF7E5;        // 1924134885
		bb[3] = 32'hBBD27277;        // 3151131255
		eexp_gcd[3] = 32'h00000087;  // 135
		aa[4] = 32'h3B23F176;        // 992211318
		bb[4] = 32'h1E8DCD3D;        // 512609597
		eexp_gcd[4] = 32'h00000001;  // 1
		i = 0;
				
                @(negedge clk)
                        ;
                @(negedge clk)
                        ;
                rst_n = 1'b0;
                @(negedge clk)
                        ;
                rst_n = 1'b1;
                @(negedge clk)
                        ;				
                repeat (10) begin
                        @(negedge clk)
                                ;
			a = aa[i];
			b = bb[i];
			exp_gcd = eexp_gcd[i];
                        load = 1;
                        @(negedge clk)
                                ;
                        load = 0;
                        @(done_event)
                                ;
                        if (gcd !== exp_gcd)
                                $error("\t\t Result is wrong GCD(%d,%d) -->: Expected = %d; Actual Result = %d", a, b, exp_gcd, gcd);
                        else
                                $display("\t\t Result is correct:  GCD(%d,%d) -->: Expected = %d; Actual Result = %d", a, b, exp_gcd, gcd);
			i = i + 1;
			if (i == 5) $stop;
                end				
                //$stop;
        end

        always begin
                #(2.5)
                   ;
                clk = ~clk;
        end

        always @(posedge clk)
                if (done) -> done_event;

endmodule
