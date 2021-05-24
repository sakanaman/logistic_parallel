# Logistic Parallel
ロジスティック写像の分岐図を並列処理によって計算するプログラム

## 概要
- pybind11を使ってpython内でC++で作ったライブラリを実行する
- logistic写像の分岐図計算が各μに対して独立した計算処理を行っていることに注目し、並列化した
- 並列化はC++の標準ライブラリである、`std::thread`を使って実装した

## 必要なもの
- C++のコンパイラ
- pythonのインタプリタ
- CMake (versionは3.18以上)

## 使い方
(1) ライブラリのビルド
```
mkdir build
cd build
cmake ..
make
```

(2) 1で生成した`*.so`みたいなファイル(`build`内にあるはず)を`logistic.py`のあるディレクトリにコピー

(3) `logistic.py`を実行する
```
python logistic.py
```
