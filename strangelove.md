`Dr. Strangelove` 在努力地为世界核平而奋斗着，因此他特别喜欢研究氢原子。

现在考虑氢原子中的一个电子从第 $ 1 $ 能级跃迁到第 $ n $ 能级再返回的过程……

__形式化地说：__氢原子的各个轨道可以认为是一根数轴，其上面有 $ 1, 2, 3, ..., n $ 的数字（能级），其中的一个电子可以被认为是数轴上的一个点，其只能处于整数位置。计该点所处的第 $ i $ 个位置为 $ p_i $，一开始，$ p_1 = 1 $，每一步可以从 $ p_i $ 可以跳到 $ p_{i + 1} \in (p_i, n] $，一直跳到 $ n $ ；之后从 $ n $ 出发，每一步可以从 $ p_i $ 跳到 $ p_{i + 1} \in [1, p_i) $，跳到 $ 1 $ 时结束。

`Dr. Strangelove` 希望知道在所有情况下，这个电子所吸收/发出的光的种类之和（根据物理知识，电子在任意两个能级间跃迁时吸收/发出的光的种类均不同，并且此题将不区分光的吸收/发出）。

__形式化地说：__对于移动的第 $ i $ 步，其可以被表示为一个__无序数对__ $ (p_i, p_{i + 1}) $；注意如果在 $ 1 \to n $ 的过程中跳了一步 $ (x, y) $，$ n \to 1 $ 的过程中跳了一步 $ (y, x) $，则这两个数对会被认为是等价的。
某种符合该移动方式的方案 $ S = p_1, p_2, p_3, ..., p_m $ 的__答案__为 $ \mathit{ans}_S = \lvert \{(p_i, p_{i + 1})\} \rvert $，即代表所有移动的无序数对的集合的大小。
输入 $ n $，求所有不同的 $ S $ 的答案之和 $ \sum_S \mathit{ans}_S \mod{10^9 + 7} $。