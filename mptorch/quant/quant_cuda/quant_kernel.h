#include <stdint.h>

__global__ void fixed_point_quantize_kernel_stochastic(float *__restrict__ a,
                                                       float *__restrict__ r,
                                                       float *o, int size,
                                                       int sigma, bool clamp,
                                                       float t_min, float t_max);

__global__ void fixed_point_quantize_kernel_nearest(float *__restrict__ a,
                                                    float *o, int size,
                                                    int sigma, bool clamp,
                                                    float t_min, float t_max);

__global__ void fixed_point_quantize_kernel_mask_stochastic(float *__restrict__ a,
                                                            float *__restrict__ r,
                                                            float *o, uint8_t *mask,
                                                            int size, int sigma,
                                                            float t_min, float t_max);

__global__ void fixed_point_quantize_kernel_mask_nearest(float *__restrict__ a,
                                                         float *o, uint8_t *mask,
                                                         int size, int sigma,
                                                         float t_min, float t_max);

__global__ void float_kernel_stochastic(float *__restrict__ a,
                                        int *__restrict__ r,
                                        float *o, int size,
                                        int man_bits, int exp_bits);

__global__ void float_kernel_nearest(float *__restrict__ a,
                                     float *o, int size,
                                     int man_bits, int exp_bits);

__global__ void block_kernel_stochastic(float *__restrict__ a,
                                        int *__restrict__ r,
                                        float *o, int size,
                                        float *max_entry,
                                        int man_bits);

__global__ void block_kernel_nearest(float *__restrict__ a,
                                     float *o, int size,
                                     float *max_entry,
                                     int man_bits);

__global__ void block_kernel_sim_stochastic(float *__restrict__ a,
                                            float *__restrict__ r,
                                            float *o, int size,
                                            float *max_entry,
                                            int wl);

__global__ void block_kernel_sim_nearest(float *__restrict__ a,
                                         float *o, int size,
                                         float *max_entry,
                                         int wl);

__global__ void tvm_gemm_fp(float *__restrict__ feature, float *__restrict__ kernel,
                         float *__restrict__ gemm, int M, int K, int N, 
                         int man_bits, int exp_bits);

__global__ void tvm_gemm_fp_fp(float *__restrict__ feature, float *__restrict__ kernel,
                         float *__restrict__ gemm, int M, int K, int N, 
                         int m_man_bits, int m_exp_bits, int a_man_bits, int a_exp_bits);

__global__ void tvm_gemm_fp_fxp(float *__restrict__ feature, float *__restrict__ kernel,
                         float *__restrict__ gemm, int M, int K, int N, 
                         int m_man_bits, int m_exp_bits, int Qi, int Qf, bool symmetric);

__global__ void tvm_gemm_fma(float *__restrict__ feature, float *__restrict__ kernel,
                        float *__restrict__ gemm, int M, int K, int N, 
                        int man_bits, int exp_bits);