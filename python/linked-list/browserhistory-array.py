class BrowserHistory(object):
    def __init__(self, homepage):
        self.li = [homepage]
        self.index = 0

    def visit(self, url):
        if self.index != len(self.li) - 1:
            for i in range(self.index + 1, len(self.li)):
                self.li.pop()
        self.li.append(url)
        self.index += 1

    def back(self, steps):
        if self.index - steps < 0:
            self.index = 0
        else:
            self.index = self.index - steps
        return self.li[self.index]

    def forward(self, steps):
        if self.index + steps > len(self.li) - 1:
            self.index = len(self.li) - 1
        else:
            self.index = self.index + steps
        return self.li[self.index]
