import random

# ============================
# CONFIG
# ============================
SIZE_DATA = 8        # số bit dữ liệu mỗi dòng
BIT_ADDR = 4        # số bit địa chỉ
SIZE_ADDR = 2 ** BIT_ADDR   # số dòng
OUTPUT_FILE = "./random_hex.txt"
# ============================

hex_digits = SIZE_DATA // 4

with open(OUTPUT_FILE, "w") as f:
    for _ in range(SIZE_ADDR):
        value = random.getrandbits(SIZE_DATA)
        hex_str = f"{value:0{hex_digits}X}"
        f.write(hex_str + "\n")

print(f"Generated {SIZE_ADDR} lines of {SIZE_DATA}-bit HEX to {OUTPUT_FILE}")
