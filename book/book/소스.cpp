class Actor
{
public:
	static void init() { current_ = 0; }
	static void swap() { current_ = next(); }

	void slap() { slapped_[next()] = true; }
	bool wasSlapped() { return slapped_[current_]; }

private:
	static int current_;
	static int next() { return 1 - current_; }

	bool slapped_[2];
};

class Stage
{
public:
	void add(Actor* actor, int index)
	{
		actors_[index] = actor;
	}
	void Stage::update()
	{
		for (int i = 0; i < NUM_ACTORS; ++i)
		{
			actors_[i]->update();
		}
		for (int i = 0; i < NUM_ACTORS; ++i)
		{
			actors_[i]->swap();
		}
	}

private:
	static const int NUM_ACTORS = 3;
	Actor* actors_[NUM_ACTORS];
};

class Comedian : public Actor
{
public:
	void face(Actor* actor) { facing_ = actor; }
	virtual void update()
	{
		if (wasSlapped())
			facing_->slap();
	}

private:
	Actor* facing_;
};

int main()
{
	Stage stage;

	Comedian* harry = new Comedian();
	Comedian* baldy = new Comedian();
	Comedian* chump = new Comedian();

	harry->face(baldy);
	baldy->face(chump);
	chump->face(harry);

	stage.add(harry, 0);
	stage.add(baldy, 1);
	stage.add(chump, 2);
}