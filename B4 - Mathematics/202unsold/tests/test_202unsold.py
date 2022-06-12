from typing import Any
from src.args import Argument
from src.main import main


def test_main(capsys: Any) -> None:
    args: Argument = Argument(a=60, b=70)
    main(args)
    assert (
        capsys.readouterr().out
        == "--------------------------------------------------------------------------------\n\tX=10\tX=20\tX=30\tX=40\tX=50\tY law\nY=10\t0.100\t0.080\t0.060\t0.040\t0.020\t0.300\nY=20\t0.083\t0.067\t0.050\t0.033\t0.017\t0.250\nY=30\t0.067\t0.053\t0.040\t0.027\t0.013\t0.200\nY=40\t0.050\t0.040\t0.030\t0.020\t0.010\t0.150\nY=50\t0.033\t0.027\t0.020\t0.013\t0.007\t0.100\nX law\t0.333\t0.267\t0.200\t0.133\t0.067\t1.000\n--------------------------------------------------------------------------------\nz\t20\t30\t40\t50\t60\t70\t80\t90\t100\np(Z=z)\t0.100\t0.163\t0.193\t0.193\t0.167\t0.100\t0.053\t0.023\t0.007\n--------------------------------------------------------------------------------\nexpected value of X:\t23.3\nvariance of X:\t\t155.6\nexpected value of Y:\t25.0\nvariance of Y:\t\t175.0\nexpected value of Z:\t48.3\nvariance of Z:\t\t330.6\n--------------------------------------------------------------------------------\n"
    )
