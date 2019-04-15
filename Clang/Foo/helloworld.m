#import "Foo.h"

int main (int argc, char *argv[]){

	@autoreleasepool {

	Foo *f = [[Foo alloc] init];
	[f run];

	return 0;
	}
}
