from typing import Optional
from torch.nn.common_types import _size_2_t
from ..number import Number
from typing import Union, Optional, Tuple

__all__ = ["QAffineFormats"]

id_quant = lambda x: x


class QAffineFormats:
    def __init__(
        self,
        fwd_mac: Optional[Union[Number, Tuple[Number, Number]]] = None,
        bwd_mac: Optional[Union[Number, Tuple[Number, Number]]] = None,
        fwd_rnd: Optional[str] = "nearest",
        bwd_rnd: Optional[str] = "nearest",
        weight_quant=id_quant,
        bias_quant=id_quant,
        input_quant=id_quant,
        output_quant=id_quant,
        grad_quant=id_quant,
    ) -> None:
        if fwd_mac is not None:
            if len(fwd_mac) > 1:
                (self.fwd_add, self.fwd_mul) = fwd_mac
                self.fwd_fma = False
            elif len(fwd_mac) == 1:
                self.fwd_add = self.fwd_mul = fwd_mac[0]
                self.fwd_fma = True
            else:
                self.fwd_add = self.fwd_mul = None
                self.fwd_fma = False
            self.use_default_prec = False
        else:
            self.use_default_prec = True

        if bwd_mac is not None:
            if len(bwd_mac) > 1:
                (self.bwd_add, self.bwd_mul) = fwd_mac
                self.bwd_fma = False
            elif len(fwd_mac) == 1:
                self.bwd_add = self.bwd_mul = fwd_mac[0]
                self.bwd_fma = True
            else:
                self.bwd_add = self.bwd_mul = None
                self.bwd_fma = False
            self.use_default_prec = False
        else:
            self.use_default_prec = True

        self.fwd_rnd = fwd_rnd
        self.bwd_rnd = bwd_rnd
        self.weight_quant = weight_quant
        self.bias_quant = bias_quant
        self.input_quant = input_quant
        self.output_quant = output_quant
        self.grad_quant = grad_quant
