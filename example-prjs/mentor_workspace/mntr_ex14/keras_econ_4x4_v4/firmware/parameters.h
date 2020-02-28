#ifndef PARAMETERS_H_
#define PARAMETERS_H_

/* #include <complex> */
/* #include "ap_int.h" */
/* #include "ap_fixed.h" */
/* #include "nnet_utils/nnet_dense.h" */
#include "nnet_utils/nnet_dense_large.h"
/* #include "nnet_utils/nnet_dense_compressed.h" */
/* #include "nnet_utils/nnet_conv.h" */
#include "nnet_utils/nnet_conv2d.h"
#include "nnet_utils/nnet_activation.h"
/* #include "nnet_utils/nnet_common.h" */
/* #include "nnet_utils/nnet_batchnorm.h" */
/* #include "nnet_utils/nnet_pooling.h" */
/* #include "nnet_utils/nnet_merge.h" */
/* #include "nnet_utils/nnet_helpers.h" */

//hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 3
#define N_INPUT_2_1 4
#define N_INPUT_3_1 4
#define OUT_HEIGHT_2 3
#define OUT_WIDTH_2 4
#define N_FILT_2 4
#define OUT_HEIGHT_4 3
#define OUT_WIDTH_4 4
#define N_FILT_4 4
#define OUT_HEIGHT_6 3
#define OUT_WIDTH_6 4
#define N_FILT_6 4
#define N_LAYER_8 12

//hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<18,8> model_default_t;
typedef ap_fixed<18,8> input_t;
typedef ap_fixed<18,8> layer2_t;
typedef ap_fixed<18,8> layer3_t;
typedef ap_fixed<18,8> layer4_t;
typedef ap_fixed<18,8> layer5_t;
typedef ap_fixed<18,8> layer6_t;
typedef ap_fixed<18,8> layer7_t;
typedef ap_fixed<18,8> layer8_t;
typedef ap_fixed<18,8> result_t;

//hls-fpga-machine-learning insert layer-config
struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = N_INPUT_1_1;
    static const unsigned in_width = N_INPUT_2_1;
    static const unsigned n_chan = N_INPUT_3_1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_2;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<18,8> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
};

struct relu_config3 : nnet::activ_config {
    static const unsigned n_in = OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config4 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_2;
    static const unsigned in_width = OUT_WIDTH_2;
    static const unsigned n_chan = N_FILT_2;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_4;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_4;
    static const unsigned out_width = OUT_WIDTH_4;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<18,8> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
};

struct relu_config5 : nnet::activ_config {
    static const unsigned n_in = OUT_HEIGHT_4*OUT_WIDTH_4*N_FILT_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config6 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = OUT_HEIGHT_4;
    static const unsigned in_width = OUT_WIDTH_4;
    static const unsigned n_chan = N_FILT_4;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_6;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_6;
    static const unsigned out_width = OUT_WIDTH_6;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<18,8> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
};

struct relu_config7 : nnet::activ_config {
    static const unsigned n_in = OUT_HEIGHT_6*OUT_WIDTH_6*N_FILT_6;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config8 : nnet::dense_config {
    static const unsigned n_in = OUT_HEIGHT_6*OUT_WIDTH_6*N_FILT_6;
    static const unsigned n_out = N_LAYER_8;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 768;
    static const bool store_weights_in_bram = false;
    typedef ap_fixed<18,8> accum_t;
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config9 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_8;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};


#endif
