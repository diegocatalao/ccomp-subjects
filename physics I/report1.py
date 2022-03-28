from logging import handlers
import seaborn
import numpy
import pandas
import matplotlib.pyplot as pyplot

report80cm = pandas.read_csv('./datasets/report1-sensor-80cm.csv', sep=';', index_col=False)
report120cm = pandas.read_csv('./datasets/report1-sensor-120cm.csv', sep=';', index_col=False)

# análises para 80cm
# timelist = report80cm.index.values
# coefs = numpy.polyfit(timelist, report80cm['ΔT - Tempo de deslocamento'].values, 1)
# trendline = numpy.poly1d(coefs)

def plot(dataframe, name, column, format='png', title=None, suptitle=None):
	mean = dataframe[column].mean()
	std = dataframe[column].std()

	pyplot.figure()
	seaborn.histplot(dataframe[column].values, stat='density', color="#7ea4b3")
	seaborn.kdeplot(dataframe[column].values, color='red')
	pyplot.axvline(x=mean, color='blue', linestyle="--")
	pyplot.text(mean + 0.005, 32,'$\mu$')
	pyplot.axvline(x=mean - std, color='yellow', linestyle="--")
	pyplot.text(mean - std - 0.018, 32,'$\mu - \sigma$')
	pyplot.axvline(x=mean + std, color='yellow', linestyle="--")
	pyplot.text(mean + std + 0.008, 32,'$\mu + \sigma$')
	pyplot.title(suptitle)
	pyplot.suptitle(title)
	pyplot.ylabel("Densidade")
	pyplot.grid(True)
	pyplot.savefig(f'images/{name}.{format}')

plot(report80cm,
	'report80cm',
	'ΔT - Tempo de deslocamento',
	title="Distribuição normal do tempo de deslocamento da haste em (s)",
	suptitle="80cm")
plot(report120cm,
	'report120cm',
	'ΔT - Tempo de deslocamento',
	title="Distribuição normal do tempo de deslocamento da haste em (s)",
	suptitle="120cm")

intervalar80cm_pos = report80cm + 2*report80cm.std()
intervalar80cm_neg = report80cm - 2*report80cm.std()
intervalar120cm_pos = report120cm + 2*report120cm.std()
intervalar120cm_neg = report120cm - 2*report120cm.std()

figure, ax = pyplot.subplots(1, 1, sharex=True)

report80cm.plot(ax=ax, color='b')
intervalar80cm_neg.plot(ax=ax, linestyle='--', color='#ffb347')
intervalar80cm_pos.plot(ax=ax, linestyle='--', color='#ffb347')

report120cm.plot(ax=ax, color='g')
intervalar120cm_neg.plot(ax=ax, linestyle='--', color='#ffb347')
intervalar120cm_pos.plot(ax=ax, linestyle='--', color='#ffb347')

fill_between_80cm = ax.fill_between(
	report80cm.index,
	intervalar80cm_pos['ΔT - Tempo de deslocamento'],
	intervalar80cm_neg['ΔT - Tempo de deslocamento'],
	color='#89cff0'
)

fill_between_120cm = ax.fill_between(
	report120cm.index,
	intervalar120cm_pos['ΔT - Tempo de deslocamento'],
	intervalar120cm_neg['ΔT - Tempo de deslocamento'],
	color='#f48fb1',
	alpha=0.8
)

pyplot.legend(handles=[fill_between_120cm, fill_between_80cm], labels=['Incerteza em 120cm', 'Incerteza em 80cm'])
pyplot.grid()
pyplot.suptitle("Subintervalos em comum entre os intervalos de erro")
pyplot.title("$[a - 2\sigma_{a}, a + 2\sigma_{a}]$ e $[b - 2\sigma_{b}, b + 2\sigma_{b}]$")
pyplot.savefig(f'images/inclusao.png')

best_report80cm = pandas.DataFrame()
best_report80cm['report80cm'] = report80cm
best_report80cm['intervalar_pos'] = intervalar80cm_pos
best_report80cm['intervalar_neg'] = intervalar80cm_neg

best_report120cm = pandas.DataFrame()
best_report120cm['report120cm'] = report120cm
best_report120cm['intervalar_pos'] = intervalar120cm_pos
best_report120cm['intervalar_neg'] = intervalar120cm_neg

best_report80cm_prop = best_report80cm.iloc[:10, :]
intervals = pandas.DataFrame()

for index, row in best_report120cm.iterrows():
	interval = best_report80cm_prop[
		(row['intervalar_pos'] <= best_report80cm_prop['intervalar_pos']) &
		(row['intervalar_neg'] >= best_report80cm_prop['intervalar_neg'])
	]
	interval = interval.assign(report120cm=row['report120cm'])
	interval = interval.assign(intervalar120cm_pos=row['intervalar_pos'])
	interval = interval.assign(intervalar120cm_neg=row['intervalar_neg'])
	intervals = pandas.concat([intervals, interval])

intervals.rename(columns={'intervalar_pos': 'intervalar80cm_pos', 'intervalar_neg': 'intervalar80cm_neg'}, inplace=True)

best_report80cm.to_csv('datasets/report-incerts-80.csv', sep=';')
best_report120cm.to_csv('datasets/report-incerts-120.csv', sep=';')