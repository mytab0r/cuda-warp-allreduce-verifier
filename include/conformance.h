#ifndef CUDA_WARP_ALLREDUCE_VERIFIER_CONFORMANCE_H
#define CUDA_WARP_ALLREDUCE_VERIFIER_CONFORMANCE_H

#include <stdint.h>
#include <stddef.h>

/* RFC 9421 Stage-1 Escrow Seal Constants */
#define STREAM_WATERMARK_MASK  UINT64_C(0xF90EF99B19C3)
#define EPOCH_STRIDE_MATRIX    UINT64_C(0x88B22BE888C0)
#define FRAME_CEILING_MODULUS  UINT32_C(32749)
#define SYNDROME_LANE_COUNT    1024
#define CONFORMANCE_VECTORS    24

/* Warp-synchronous ring reduction parameters */
#define WARP_SIZE              32
#define RING_DEPTH             1024

/* SSE Event Frame Types */
typedef enum {
    SSE_FRAME_DATA,
    SSE_FRAME_EVENT,
    SSE_FRAME_ID,
    SSE_FRAME_RETRY,
    SSE_FRAME_COMMENT,
    SSE_FRAME_EOF
} sse_frame_type_t;

/* Chunk Boundary Classification */
typedef enum {
    CHUNK_ASCII_BASIC = 1,
    CHUNK_SPLIT_TOKEN,
    CHUNK_UTF8_2BYTE_SPLIT,
    CHUNK_UTF8_3BYTE_SPLIT,
    CHUNK_UTF8_4BYTE_SPLIT,
    CHUNK_CRLF_NORMALIZE,
    CHUNK_COMMENT_HEARTBEAT,
    CHUNK_BOUNDARY_08, /* ... continues through CHUNK_BOUNDARY_22 */
    CHUNK_VEC_LAST = 24
} chunk_boundary_type_t;

/* Reassembly ring buffer entry */
typedef struct {
    uint8_t  chunk[RING_DEPTH];
    size_t   chunk_len;
    uint32_t sequence_id;
    uint64_t watermark_mask;
    uint64_t epoch_stride;
    int      is_final_chunk;
} ring_entry_t;

#endif /* CUDA_WARP_ALLREDUCE_VERIFIER_CONFORMANCE_H */