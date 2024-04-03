def yield_rate(bond_price, bond_facePrice, cash, time_of_discounts_cash, time_of_discounts_face, accuracy=None):
    '''
    :param bond_price: 债券价格
    :param bond_facePrice: 债券面值
    :param cash: 每期贴现值
    :param time_of_discounts_cash: 现金贴现次数
    :param time_of_discounts_face: 面值贴现伪次数
    :param accuracy: 精度（精确到多少分位置）
    :return: 到期收益率
    '''

    loss = float('inf')
    rate_list = [float(x) / 1000000 for x in range(1, 200000, 1)]
    for rate in rate_list:
        pre_price = cash * (1 - (1 / pow((1 + rate), time_of_discounts_cash))) / rate + \
                    (bond_facePrice / pow((1 + rate), time_of_discounts_face))
        pre_loss = abs(bond_price - pre_price)
        if pre_loss < loss:
            loss = pre_loss
            rate_hat = rate
    return rate_hat


print(yield_rate(bond_price=973.55,
                 bond_facePrice=1000,
                 cash=41,
                 time_of_discounts_cash=8,
                 time_of_discounts_face=8))


def get_price(rate, bond_facePrice, cash, time_of_discounts_cash, time_of_discounts_face):
    '''
    :param rate: 到期收益率
    :param bond_facePrice: 面值
    :param cash: 每期贴现值
    :param time_of_discounts_cash: 贴现次数
    :param time_of_discounts_face: 面值持续次数
    :return: 价格
    '''
    bond_price = cash * (1 - (1 / pow((1 + rate), time_of_discounts_cash))) / rate + \
                 (bond_facePrice / pow((1 + rate), time_of_discounts_face))
    return bond_price


print(get_price(rate=0.03,
                bond_facePrice=100,
                cash=3,
                time_of_discounts_cash=30,
                time_of_discounts_face=30))
