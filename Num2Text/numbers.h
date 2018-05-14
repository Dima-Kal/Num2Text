#define NUMBERS_H
#define DEFAULT 3

/* structure of command name */
typedef struct {
	char *name;
}NUMBERS;

NUMBERS single[]={
		{"zero"},
		{"one"},
		{"two"},
		{"three"},
		{"four"},
		{"five"},
		{"six"},
		{"seven"},
		{"eight"},
		{"nine"},
};

NUMBERS tens[]={
		{"twenty"},
		{"thirty"},
		{"forty"},
		{"fifty"},
		{"sixty"},
		{"seventy"},
		{"eighty"},
		{"ninety"},
};

NUMBERS other[]={
		{"eleven"},
		{"twelve"},
		{"thirteen"},
		{"fourteen"},
		{"fifteen"},
		{"sixteen"},
		{"seventeen"},
		{"eighteen"},
		{"nineteen"},
};
