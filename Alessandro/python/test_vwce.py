import main

def test_mean():
    values = [1.0, 2.0, 3.0, 4.0, 5.0]
    assert main.mean(values) == 3.0
    assert main.mean([]) == 0.0