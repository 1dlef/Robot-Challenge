

class Command {

public:
     virtual void execute() = 0;
};


class PlaceCmd: public Command {
    

};

class FaceCmd: public Command {

};

class MoveCmd: public Command {

};

class ReportCmd: public Command {

};


