import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

def main():
    folder = "/home/qq43/KIB/python/pythonData/data/"
    kc_tax = pd.read_csv(folder + "kc_tax.csv.gz")
    
    kc_tax0 = kc_tax.loc[(kc_tax.TaxAssessedValue < 750000) &
                        (kc_tax.SqFtTotLiving > 100) &
                        (kc_tax.SqFtTotLiving < 3500), :]
    print(kc_tax0.shape)
    print(kc_tax0.head())
    print(kc_tax0.info())
    
    ax = kc_tax0.plot.hexbin(x='SqFtTotLiving', y='TaxAssessedValue', gridsize=30, sharex=False, figsize=(5, 4))
    ax.set_xlabel('Finished Square Feet')
    ax.set_ylabel('Tax Assessed Value')
    plt.tight_layout()
    
    fig = plt.figure()
    fig, ax = plt.subplot(figsize=(6,6))
    ax = sns.kdeplot(data=kc_tax0, x='SqFtTotLiving', y='TaxAssessedValue', ax=ax)
    ax.set_xlabel('Finished Square Feet')
    ax.set_ylabel('Tax Assessed Value')
    
    plt.show()


if __name__ == "__main__":
    main()