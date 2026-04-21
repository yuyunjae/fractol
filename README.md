## mlx 를 이용해 fractol을 만들어보자!

## 실행 순서
```bash
git clone https://github.com/yuyunjae/fractol.git
cd fractol
git clone --depth=1 https://github.com/melaniereis/minilibx_opengl_20191021.git mlx
make -C mlx
make
./fractol mandelbrot
```


## fractol 종류
<br> 1. julia set
<br> 2. mandelbrot set
<br> 3. burning ship fractal


## 실행 방법
```bash
# 1
./fractol mandelbrot

# 2
./fractol julia "[real_number]" "[imaginary number]"

# 3
./fractol my_fractol
```

줄리아 집합은 허수부에 반드시 `i`를 붙이고 따옴표로 감싸야 합니다.

### 줄리아 집합 예시
```bash
./fractol julia "-0.8" "0.156i"      # 고전적인 줄리아
./fractol julia "-0.7269" "0.1889i"  # 꽃잎 모양
./fractol julia "0.285" "0.01i"      # 가늘고 긴 구조
./fractol julia "-0.4" "0.6i"        # 소용돌이
```


## 조작법

### 마우스
| 동작 | 기능 |
|---|---|
| 좌클릭 | 클릭한 지점을 화면 중심으로 이동 |
| 휠 업 | 커서 위치 기준 2배 확대 |
| 휠 다운 | 커서 위치 기준 2배 축소 |

### 키보드 — 이동
| 키 | 기능 |
|---|---|
| ↑ | 위로 이동 |
| ↓ | 아래로 이동 |
| ← | 왼쪽으로 이동 |
| → | 오른쪽으로 이동 |

이동 거리는 `0.03125 / scope` 공식으로 계산되어, 확대할수록 더 섬세하게 움직입니다.

### 키보드 — 색상
| 키 | 색상 |
|---|---|
| R | 빨강 |
| G | 초록 |
| B | 파랑 (기본값) |

### 종료
| 키 | 기능 |
|---|---|
| ESC | 종료 |
| 창 X 버튼 | 종료 |


## 내부 설정 (fractol.h)
- `WIN_X`, `WIN_Y` : 창 크기 (기본 1920 × 1080)
- `ITER_MAX` : 최대 반복 횟수 (기본 500)
- 초기 배율 `scope = 0.25` — 처음 실행 시 프랙탈 전체가 보이는 스케일
