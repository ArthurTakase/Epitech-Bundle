from src.display import (
    display_density,
    display_percentage_above_qi,
    display_percentage_between_qi,
)
from src.compute import noIQ, computeIQ
from src.args import Arguments
from typing import List, Any


def test_display_density_example(capsys: Any) -> None:
    densities: List[float] = noIQ(Arguments(100, 15, None, None))
    display_density(densities)

    assert (
        capsys.readouterr().out
        == "0 0.00000\n1 0.00000\n2 0.00000\n3 0.00000\n4 0.00000\n5 0.00000\n6 0.00000\n7 0.00000\n8 0.00000\n9 0.00000\n10 0.00000\n11 0.00000\n12 0.00000\n13 0.00000\n14 0.00000\n15 0.00000\n16 0.00000\n17 0.00000\n18 0.00000\n19 0.00000\n20 0.00000\n21 0.00000\n22 0.00000\n23 0.00000\n24 0.00000\n25 0.00000\n26 0.00000\n27 0.00000\n28 0.00000\n29 0.00000\n30 0.00000\n31 0.00000\n32 0.00000\n33 0.00000\n34 0.00000\n35 0.00000\n36 0.00000\n37 0.00000\n38 0.00001\n39 0.00001\n40 0.00001\n41 0.00001\n42 0.00002\n43 0.00002\n44 0.00003\n45 0.00003\n46 0.00004\n47 0.00005\n48 0.00007\n49 0.00008\n50 0.00010\n51 0.00013\n52 0.00016\n53 0.00020\n54 0.00024\n55 0.00030\n56 0.00036\n57 0.00044\n58 0.00053\n59 0.00063\n60 0.00076\n61 0.00091\n62 0.00107\n63 0.00127\n64 0.00149\n65 0.00175\n66 0.00204\n67 0.00236\n68 0.00273\n69 0.00314\n70 0.00360\n71 0.00410\n72 0.00466\n73 0.00526\n74 0.00592\n75 0.00663\n76 0.00739\n77 0.00821\n78 0.00907\n79 0.00998\n80 0.01093\n81 0.01192\n82 0.01295\n83 0.01399\n84 0.01506\n85 0.01613\n86 0.01721\n87 0.01827\n88 0.01931\n89 0.02033\n90 0.02130\n91 0.02221\n92 0.02307\n93 0.02385\n94 0.02455\n95 0.02516\n96 0.02567\n97 0.02607\n98 0.02636\n99 0.02654\n100 0.02660\n101 0.02654\n102 0.02636\n103 0.02607\n104 0.02567\n105 0.02516\n106 0.02455\n107 0.02385\n108 0.02307\n109 0.02221\n110 0.02130\n111 0.02033\n112 0.01931\n113 0.01827\n114 0.01721\n115 0.01613\n116 0.01506\n117 0.01399\n118 0.01295\n119 0.01192\n120 0.01093\n121 0.00998\n122 0.00907\n123 0.00821\n124 0.00739\n125 0.00663\n126 0.00592\n127 0.00526\n128 0.00466\n129 0.00410\n130 0.00360\n131 0.00314\n132 0.00273\n133 0.00236\n134 0.00204\n135 0.00175\n136 0.00149\n137 0.00127\n138 0.00107\n139 0.00091\n140 0.00076\n141 0.00063\n142 0.00053\n143 0.00044\n144 0.00036\n145 0.00030\n146 0.00024\n147 0.00020\n148 0.00016\n149 0.00013\n150 0.00010\n151 0.00008\n152 0.00007\n153 0.00005\n154 0.00004\n155 0.00003\n156 0.00003\n157 0.00002\n158 0.00002\n159 0.00001\n160 0.00001\n161 0.00001\n162 0.00001\n163 0.00000\n164 0.00000\n165 0.00000\n166 0.00000\n167 0.00000\n168 0.00000\n169 0.00000\n170 0.00000\n171 0.00000\n172 0.00000\n173 0.00000\n174 0.00000\n175 0.00000\n176 0.00000\n177 0.00000\n178 0.00000\n179 0.00000\n180 0.00000\n181 0.00000\n182 0.00000\n183 0.00000\n184 0.00000\n185 0.00000\n186 0.00000\n187 0.00000\n188 0.00000\n189 0.00000\n190 0.00000\n191 0.00000\n192 0.00000\n193 0.00000\n194 0.00000\n195 0.00000\n196 0.00000\n197 0.00000\n198 0.00000\n199 0.00000\n200 0.00000\n"
    )


def test_display_percentage_above_qi(capsys: Any) -> None:
    args: Arguments = Arguments(100, 24, 90, None)
    percentage: float = computeIQ(0, 90, args)
    display_percentage_above_qi(percentage, args)

    assert capsys.readouterr().out == "33.8% of people have an IQ inferior to 90\n"


def test_display_percentage_between_qi(capsys: Any) -> None:
    args: Arguments = Arguments(100, 24, 90, 95)
    percentage: float = computeIQ(90, 95, args)
    display_percentage_between_qi(percentage, args)

    assert capsys.readouterr().out == "7.9% of people have an IQ between 90 and 95\n"