#include "fl/Headers.h"

int main()
{



	using namespace fl;

	Engine* engine = new Engine;
	engine->setName("Car steering");
	engine->setDescription("");

	InputVariable* obstacle = new InputVariable;
	obstacle->setName("obstacle");
	obstacle->setDescription("");
	obstacle->setEnabled(true);
	obstacle->setRange(0.000, 90.000);
	obstacle->setLockValueInRange(false);
	obstacle->addTerm(new Ramp("1", 0.000, 10.000));
	obstacle->addTerm(new Ramp("2", 11.000, 20.000));
	obstacle->addTerm(new Ramp("3", 21.000, 30.000));
	obstacle->addTerm(new Ramp("4", 31.000, 40.000));
	obstacle->addTerm(new Ramp("5", 41.000, 50.000));
	obstacle->addTerm(new Ramp("6", 51.000, 60.000));
	obstacle->addTerm(new Ramp("7", 61.000, 70.000));
	obstacle->addTerm(new Ramp("8", 71.000, 80.000));
	obstacle->addTerm(new Ramp("9", 81.000, 90.000));
	engine->addInputVariable(obstacle);

	InputVariable* speed = new InputVariable;
	speed->setName("speed");
	speed->setDescription("");
	speed->setEnabled(true);
	speed->setRange(0.000, 90.000);
	speed->setLockValueInRange(false);
	speed->addTerm(new Ramp("1", 0.000, 10.000));
	speed->addTerm(new Ramp("2", 11.000, 20.000));
	speed->addTerm(new Ramp("3", 21.000, 30.000));
	speed->addTerm(new Ramp("4", 31.000, 40.000));
	speed->addTerm(new Ramp("5", 41.000, 50.000));
	speed->addTerm(new Ramp("6", 51.000, 60.000));
	speed->addTerm(new Ramp("7", 61.000, 70.000));
	speed->addTerm(new Ramp("8", 71.000, 80.000));
	speed->addTerm(new Ramp("9", 81.000, 90.000));
	engine->addInputVariable(speed);


	OutputVariable* distance = new OutputVariable;
	distance->setName("distance");
	distance->setDescription("");
	distance->setEnabled(true);
	distance->setRange(0.000, 90.000);
	distance->setLockValueInRange(false);
	distance->setAggregation(new Maximum);
	distance->setDefuzzifier(new Centroid());
	distance->setDefaultValue(0.0);
	distance->setLockPreviousValue(false);
	distance->addTerm(new Ramp("1", 0.000, 10.000));
	distance->addTerm(new Ramp("2", 11.000, 20.000));
	distance->addTerm(new Ramp("3", 21.000, 30.000));
	distance->addTerm(new Ramp("4", 31.000, 40.000));
	distance->addTerm(new Ramp("5", 41.000, 50.000));
	distance->addTerm(new Ramp("6", 51.000, 60.000));
	distance->addTerm(new Ramp("7", 61.000, 70.000));
	distance->addTerm(new Ramp("8", 71.000, 80.000));
	distance->addTerm(new Ramp("9", 81.000, 90.000));
	engine->addOutputVariable(distance);
	
	RuleBlock* rules = new RuleBlock;
	rules->setName("rules");
	rules->setDescription("");
	rules->setEnabled(true);
	rules->setConjunction(new Minimum());
	rules->setDisjunction(fl::null);
	rules->setImplication(new AlgebraicProduct);
	rules->setActivation(new General);

	rules->addRule(Rule::parse("if obstacle is 3 and speed is 9 then distance is 1", engine));
	rules->addRule(Rule::parse("if obstacle is 3 and speed is 8 then distance is 2", engine));
	rules->addRule(Rule::parse("if obstacle is 3 and speed is 7 then distance is 3", engine));
	rules->addRule(Rule::parse("if obstacle is 3 and speed is 6 then distance is 4", engine));
	rules->addRule(Rule::parse("if obstacle is 3 and speed is 5 then distance is 5", engine));
	rules->addRule(Rule::parse("if obstacle is 3 and speed is 4 then distance is 6", engine));
	rules->addRule(Rule::parse("if obstacle is 3 and speed is 3 then distance is 7", engine));
	rules->addRule(Rule::parse("if obstacle is 3 and speed is 2 then distance is 8", engine));
	rules->addRule(Rule::parse("if obstacle is 3 and speed is 1 then distance is 9", engine));
	engine->addRuleBlock(rules);


	std::string status{};
	if (not engine->isReady(&status))
	{
		throw Exception("[engine error] engine is not ready:n" + status, FL_AT);
	}
	else
	{
		scalar distance_obstacle{28.000f};
		scalar speed_car{90.000f};
		int tab[10]{};
		size_t counter{};
		while(speed_car >= 0)
		{
			obstacle->setValue(distance_obstacle);
			speed->setValue(speed_car);
			engine->process();
			tab[counter] = engine->getOutputValue("distance");
			++counter;
			speed_car -= 10.0f;
		}
		counter = 9;
		speed_car = 90.f;

		std::cout << "Speed IN" << '\t' << "Obstacle IN" << '\t' << "Distance OUT" << '\n';
		while (speed_car >= 0)
		{
			if (speed_car == 90.f)
			{
				//FL_LOG("speed.input = " << Op::str(speed_car) << " ," << " obstacle.input = " << Op::str(distance_obstacle) << " distance.output = " << 90 << '\n');
				std::cout<< Op::str(speed_car) << "\t\t" << Op::str(distance_obstacle) << "\t\t" << 90 << '\n';
				
				counter--;
			}
			else
			{
				//FL_LOG("speed.input = " << Op::str(speed_car) << " ," << " obstacle.input = " << Op::str(distance_obstacle) << " distance.output = " << tab[counter--] << '\n');
				std::cout << Op::str(speed_car) << "\t \t" << Op::str(distance_obstacle) << "\t\t" << tab[counter--] << '\n';
			}
			speed_car -= 10.0f;
		}
	}

	system("pause");
	return 0;
}
