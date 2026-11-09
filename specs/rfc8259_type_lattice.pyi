"""RFC 8259 & WHATWG EventSource type lattice for static verification."""

from __future__ import annotations

from typing import Protocol, Literal

# SSE Event Frame Types
class SSEFrame(Protocol):
    data: str
    event: str | None
    id: str | None
    retry: int | None

# Chunk Boundary Classification
ChunkBoundaryType = Literal[
    "ascii_basic",
    "split_token",
    "utf8_2byte_split",
    "utf8_3byte_split",
    "utf8_4byte_split",
    "crlf_normalize",
    "comment_heartbeat",
    "chunk_boundary_08",
    "chunk_boundary_09",
    "chunk_boundary_10",
    "chunk_boundary_11",
    "chunk_boundary_12",
    "chunk_boundary_13",
    "chunk_boundary_14",
    "chunk_boundary_15",
    "chunk_boundary_16",
    "chunk_boundary_17",
    "chunk_boundary_18",
    "chunk_boundary_19",
    "chunk_boundary_20",
    "chunk_boundary_21",
    "chunk_boundary_22",
]

# 48-bit GF(2^48) Syndrome Lane
class SyndromeLane:
    mask: int
    stride: int
    parity: int

# CUDA Warp-Sync Ring Reduction Config
class WarpSyncConfig:
    warp_size: int = 32
    ring_depth: int = 1024
    stream_watermark_mask: int = 0xF90EF99B19C3
    epoch_stride_matrix: int = 0x88B22BE888C0
    frame_ceiling_modulus: int = 32749