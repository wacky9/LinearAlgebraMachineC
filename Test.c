#include "Interpreter.h"
#include <stdio.h>
#include <string.h>

bool SM_positive();
bool SM_negative();
bool SM_zero();

bool ADD_regular();
bool ADD_zero();

bool MUL_square();
bool MUL_two_vecs();
bool MUL_identity();

bool TRN_square();
bool TRN_col();
bool TRN_row();

bool GAU_E_square();
bool GAU_B_square();
bool GAU_pivot_demonstration();

bool substring_1();
bool substring_2();
bool tokenize_new();
bool tokenize_new_mat();
bool tokenize_out();
bool dimension_vec();
bool dimension_matrix();
bool interpret_vec();
bool interpret_matrix();
bool interpret_mat_decl();
bool interpret_num_decl();
bool func_block_one_param();
bool func_block_many_params();
bool func_block_nested_params();
bool validate_three();
bool validate_four();
bool validate_wrong_num();
bool validate_three_incorrect();
bool validate_four_incorrect();

bool hashing_check();

bool scal_mul_tests(){
    bool a = SM_positive();
    bool b = SM_negative();
    bool c = SM_zero();
    return a && b && c;
}

bool add_tests(){
    bool a = ADD_zero();
    bool b = ADD_regular();
    return a && b;
}

bool mul_tests(){
    bool a = MUL_square();
    bool b = MUL_two_vecs();
    bool c = MUL_identity();
    return a && b && c;
}

bool gau_tests(){
    bool a = GAU_E_square();
    bool b = GAU_B_square();
    bool c = GAU_pivot_demonstration();
    return a && b && c;
}

bool transpose_tests(){
    bool a = TRN_square();
    bool b = TRN_col();
    bool c = TRN_row();
    return a&&b&&c;
}

bool interpreter_tests(){
    bool a = substring_1();
    bool b = substring_2();
    bool c = tokenize_new();
    bool d = tokenize_out();
    tokenize_new_mat();
    bool e = dimension_vec();
    bool f = dimension_matrix();
    bool g = interpret_vec();
    bool h = interpret_matrix();
    interpret_mat_decl();
    interpret_num_decl();
    bool i = func_block_many_params(); 
    bool j = func_block_nested_params();
    bool k = func_block_one_param();
    validate_three();
    validate_four();
    validate_wrong_num();
    validate_four_incorrect();
    validate_three_incorrect();
    return a && b && c && d && e && f && i && j && k;
}

bool depot_tests(){
    bool a = hashing_check();
    return a;
}

bool SM_positive(){
    double array[4] = {3.3, 4.5, 6, -5};
    Mat* mat = arr_constructor((short)2,(short)2,array);
    mat = scal_mul(mat,2.0);
    double arr[4] = {6.6,9,12,-10};
    Mat* expected = arr_constructor((short)2,(short)2,arr);
    bool outcome = same_mat(mat,expected);
    #if TEST > 1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    unravel_mat(mat);
    unravel_mat(expected);
    return outcome;
}
bool SM_negative(){
    //Negative
    double array[4] = {3.3, 4.5, 6, -5};
    Mat* mat = arr_constructor((short)4,(short)1,array);
    mat = scal_mul(mat,-1.0);
    double arr[4] = {-3.3,-4.5,-6,5};
    Mat* expected = arr_constructor((short)4,(short)1,arr);
    bool outcome = same_mat(mat,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    unravel_mat(mat);
    unravel_mat(expected);
}

bool SM_zero(){
    double array[4] = {3.3, 4.5, 6, -5};
    Mat* mat = arr_constructor((short)1,(short)4, array);
    mat = scal_mul(mat,0.0);
    double arr[4] = {0.0,0.0,0.0,0.0};
    Mat* expected = arr_constructor((short)1,(short)4,arr);
    bool outcome = same_mat(mat,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    unravel_mat(mat);
    unravel_mat(expected);
    return outcome;
}

bool ADD_zero(){
    double array[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
    Mat* mat_A = arr_constructor((short)2,(short)3,array);
    Mat* mat_B = arr_constructor((short)2, (short)3,array);
    Mat* expected = arr_constructor((short)2, (short)3,array);
    mat_A = add(mat_A,mat_B);
    bool outcome = same_mat(mat_A,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat_A);
    }
    #endif
    return outcome;
}

bool ADD_regular(){
    double array[6] = {1.0,2.0,3.0,4.0,5.0,6.0};
    double arr[6] = {-6.0,-5.0,-4.0,-3.0,-2.0,-1.0};
    double arr_exp[6] = {-5.0,-3.0,-1.0,1.0,3.0,5.0};
    Mat* mat_A = arr_constructor((short)3,(short)2,array);
    Mat* mat_B = arr_constructor((short)3, (short)2,arr);
    Mat* expected = arr_constructor((short)3, (short)2, arr_exp);
    mat_A = add(mat_A,mat_B);
    bool outcome = same_mat(mat_A,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat_A);
    }
    #endif
    return outcome;
}

bool MUL_square(){
    double array[4] = {1.0,2.0,3.0,4.0};
    double arr[4] = {5.0,6.0,0.0,7.0};
    double arr_exp[4] = {5.0,20.0,15.0,46.0};
    Mat* mat_A = arr_constructor((short)2,(short)2,array);
    Mat* mat_B = arr_constructor((short)2, (short)2,arr);
    Mat* expected = arr_constructor((short)2, (short)2, arr_exp);
    mat_A = compose(mat_A,mat_B);
    bool outcome = same_mat(mat_A,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat_A);
    }
    #endif
    return outcome;
}

bool MUL_two_vecs(){
    double array[3] = {1.0,3.0,9.0};
    double arr[3] = {2.0,4.0,16.0};
    double arr_exp[1] = {158.0};
    Mat* mat_A = arr_constructor((short)1,(short)3,array);
    Mat* mat_B = arr_constructor((short)3, (short)1,arr);
    Mat* expected = arr_constructor((short)1, (short)1, arr_exp);
    mat_A = compose(mat_A,mat_B);
    bool outcome = same_mat(mat_A,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat_A);
    }
    #endif
    return outcome;
}

bool MUL_identity(){
    double array[4] = {-5.0,9.0,3.0,-1.0};
    double arr[4] = {1.0,0.0,0.0,1.0};
    Mat* mat_A = arr_constructor((short)2,(short)2,array);
    Mat* mat_B = arr_constructor((short)2, (short)2,arr);
    Mat* expected = arr_constructor((short)2, (short)2, array);
    mat_A = compose(mat_A,mat_B);
    bool outcome = same_mat(mat_A,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat_A);
    }
    #endif
    return outcome;
}

bool TRN_square(){
    double array[16] = {5.0,4.0,3.0,1.0,-6.0,7.0,9.0,1.0,2.0,3.0,41.0,12.0,0.0,0.0,6.0,1.0};
    double arrayExp[16] = {5.0,-6.0,2.0,0.0,4.0,7.0,3.0,0.0,3.0,9.0,41.0,6.0,1.0,1.0,12.0,1.0};
    Mat* mat = arr_constructor((short)4,(short)4,array);
    Mat* expected = arr_constructor((short)4,(short)4,arrayExp);
    mat = transpose(mat);
    bool outcome = same_mat(mat,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSES\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    return outcome;
}

bool TRN_row(){
    double arr[4] = {1.0,0.0,1.0,0.0};
    Mat* mat_A = arr_constructor((short)4,(short)1,arr);
    Mat* expected = arr_constructor((short)1, (short)4,arr);
    mat_A = transpose(mat_A);
    bool outcome = same_mat(mat_A,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat_A);
    }
    #endif
    return outcome;
}

bool TRN_col(){

    double arr[4] = {1.0,0.0,1.0,0.0};
    Mat* mat_A = arr_constructor((short)1,(short)4,arr);
    Mat* expected = arr_constructor((short)4, (short)1,arr);
    mat_A = transpose(mat_A);
    bool outcome = same_mat(mat_A,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat_A);
    }
    #endif
    return outcome;
}

bool GAU_E_square(){
    double arr[6] = {3,4,5,1,7,-2};
    Mat* mat = arr_constructor(2,3,arr);
    double sol[6] = {3,4,5,0,5.66666,-3.66666};
    Mat* expected = arr_constructor(2,3,sol);
    mat = elimination(mat);
    bool outcome = same_mat(mat,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    return outcome;
}

bool GAU_B_square(){
    double arr[6] = {3,4,5,1,7,-2};
    Mat* mat = arr_constructor(2,3,arr);
    double sol[2] = {2.529412,-0.647059};
    Mat* expected = arr_constructor(2,1,sol);
    mat = elimination(mat);
    mat = backsubstitution(mat);
    bool outcome = same_mat(mat,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    return outcome;
}

bool GAU_pivot_demonstration(){
    double arr[6] = {1.0,1.0,2.0,1.0,1.001,2.001};
    Mat* mat = arr_constructor(2,3,arr);
    double sol[2] = {2,0};
    Mat* expected = arr_constructor(2,1,sol);
    mat = elimination(mat);
    mat = backsubstitution(mat);
    bool outcome = same_mat(mat,expected);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    return outcome;
}

bool substring_1(){
    char* str = "Hello World";
    char* expected = "Hello";
    char* actual = substring(str,0,5);
    bool outcome = strcmp(expected,actual) == 0;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        printf(actual);
        printf("\n");
    }
    #endif
    return outcome;
}

bool substring_2(){
    char* str = "Hello World";
    char* expected = "lo Wor";
    char* actual = substring(str,3,9);
    bool outcome = strcmp(expected,actual) == 0;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        printf(actual);
        printf("\n");
    }
    #endif
    return outcome;
}

bool tokenize_new(){
    char line[] = "MAT A = blah";
    char* expected_1 = "MAT";
    char* expected_2 = "A";
    char* expected_3 = "=";
    char* expected_4 = "blah";
    char** actual = tokenize_line(line);
    bool outcome = strcmp(expected_1,actual[0])==0 && strcmp(expected_2,actual[1])==0 && strcmp(expected_3,actual[2])==0 && strcmp(expected_4,actual[3]) == 0;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        for(int i = 0; i<4; i++){
            printf(actual[i]);
            printf(" ");
        }
        printf("\n");

    }
    #endif
    return outcome;
}

bool tokenize_new_mat(){
    char line[] = "MAT A = [3.5,2;-1,6.2]";
    char* expected_1 = "MAT";
    char* expected_2 = "A";
    char* expected_3 = "=";
    char* expected_4 = "[3.5,2;-1,6.2]";
    char** actual = tokenize_line(line);
    bool outcome = strcmp(expected_1,actual[0])==0 && strcmp(expected_2,actual[1])==0 && strcmp(expected_3,actual[2])==0 && strcmp(expected_4,actual[3]) == 0;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        for(int i = 0; i<4; i++){
            printf(actual[i]);
            printf(" ");
        }
        printf("\n");

    }
    #endif
    return outcome;
}

bool tokenize_out(){
    char line[] = "OUT = XK";
    char* expected_1 = "OUT";
    char* expected_2 = "=";
    char* expected_3 = "XK";
    char** actual = tokenize_line(line);
    bool outcome = strcmp(expected_1,actual[0])==0 && strcmp(expected_2,actual[1])==0 && strcmp(expected_3,actual[2]) == 0;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        for(int i = 0; i<2; i++){
            printf(actual[i]);
        }
        printf("\n");

    }
    #endif
    return outcome;
}

bool dimension_vec(){
    char* text = "3,4,-1.5";
    short* dimensions = dimension_string_mat(text);
    bool outcome = dimensions[0] == 1 && dimensions[1] == 3;
    #if TEST >1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        printf("%d ",dimensions[0]);
        printf("%d\n", dimensions[1]);
    }
    #endif
    return outcome;
}

bool dimension_matrix(){
    char* text = "3,2; 1,5.3; -2,-1";
    short* dimensions = dimension_string_mat(text);
    bool outcome = dimensions[0] == 3 && dimensions[1] == 2;
    #if TEST >1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        printf("%d ",dimensions[0]);
        printf("%d\n", dimensions[1]);
    }
    #endif
    return outcome;
}

bool interpret_vec(){
    char* text = "3,4,5,6";
    Mat* mat = interpret_mat(text);
    double arr[4] = {3.0,4.0,5.0,6.0};
    Mat* expected_mat = arr_constructor((short)1,(short)4,arr);
    bool outcome = same_mat(mat,expected_mat);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    return outcome;
}

bool interpret_matrix(){
    char* text = "-1,4;5,19.3";
    Mat* mat = interpret_mat(text);
    double arr[4] = {-1.0,4.0,5.0,19.3};
    Mat* expected_mat = arr_constructor((short)2,(short)2,arr);
    bool outcome = same_mat(mat,expected_mat);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(mat);
    }
    #endif
    return outcome;
}

bool interpret_mat_decl(){
    char* text = "[-1,4;5,19.3]";
    Value* val = interpret_declaration(text);
    double arr[4] = {-1.0,4.0,5.0,19.3};
    Mat* expected_mat = arr_constructor((short)2,(short)2,arr);
    bool outcome = same_mat(val->mat,expected_mat);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        p_mat(val->mat);
    }
    #endif
    return outcome;
}

bool interpret_num_decl(){
    char* text = "-0.5";
    Value* val = interpret_declaration(text);
    double expected_num = -0.5;
    bool outcome = equal_double(val->num,expected_num);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
        printf("%d\n",val->num);
    }
    #endif
    return outcome;
}

bool func_block_one_param(){
    char* text = "transpose(blah)";
    char* name = "transpose";
    char* param_one = "blah";
    char** result = func_sub_blocks(text);
    bool outcome = strcmp(result[0],name)== 0 && strcmp(result[1], param_one) == 0;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED]n");
        printf("%s ",result[0]);
        printf("%s\n",result[1]);
    }
    #endif
}

bool func_block_many_params(){
    char* text = "add([3,5;2,-6.0],C)";
    char* name = "add";
    char* param_one = "[3,5;2,-6.0]";
    char* param_two = "C";
    char** result = func_sub_blocks(text);
    bool outcome = strcmp(result[0],name)== 0 && strcmp(result[1], param_one) == 0 && strcmp(result[2],param_two) == 0;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED]n");
        printf("%s ",result[0]);
        printf("%s",result[1]);
        printf("%s\n",result[2]);
    }
    #endif
}

bool func_block_nested_params(){
    char* text = "add(transpose(A),B)";
    char* name = "add";
    char* param_one = "transpose(A)";
    char* param_two = "B";
    char** result = func_sub_blocks(text);
    bool outcome = strcmp(result[0],name)== 0 && strcmp(result[1], param_one) == 0 && strcmp(result[2],param_two) == 0;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED]n");
        printf("%s ",result[0]);
        printf("%s",result[1]);
        printf("%s\n",result[2]);
    }
    #endif
}

bool validate_three(){
    char* tokens[4] = {"A","=","15.6",NULL};
    bool expected = true;
    bool outcome = expected == validate_tokens(tokens);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }
    #endif
    return outcome;
}

bool validate_four(){
    char* tokens[5] = {"MAT","A","=","15.6",NULL};
    bool expected = true;
    bool outcome = expected == validate_tokens(tokens);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }
    #endif
    return outcome;
}

bool validate_wrong_num(){
    char* tokens[6] = {"MAT","A","=","15.6","YO",NULL};
    bool expected = false;
    bool outcome = expected == validate_tokens(tokens);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }
    #endif
    return outcome;
}

bool validate_four_incorrect(){
    char* tokens[5] = {"OUT","A","=","YO",NULL};
    bool expected = false;
    bool outcome = expected == validate_tokens(tokens);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }
    #endif
    return outcome;
}

bool validate_three_incorrect(){
    char* tokens[4] = {"A","15.6","YO",NULL};
    bool expected = false;
    bool outcome = expected == validate_tokens(tokens);
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
    } else {
        printf("TEST FAILED\n");
    }
    #endif
    return outcome;
}

/*Depot Tests*/

bool hashing_check(){
    int a = location("Hello");
    int b = location("Hello");
    int c = location("hello");
    int d = location("A");
    int e = location("B");
    bool outcome = a == b && b != c && d != e;
    #if TEST>1
    if(outcome){
        printf("TEST PASSED\n");
        printf("Hello: %d\n",a);
        printf("hello: %d\n", c);
        printf("A: %d\n",d);
        printf("B: %d\n",e);
    } else{
        printf("TEST FAILED\n");
        printf("HelloA: %d\n",a);
        printf("HelloB: %d\n", b);
        printf("hello: %d",c);
        printf("A: %d\n",d);
        printf("B: %d\n",e);
    }
    #endif
    return outcome;
}