#pragma once

#include "eng/engine.hpp"
#include "eng/scene.hpp"
#include "key.hpp"
#include "vector2.hpp"

namespace uppr::app {

class PerfScene : public eng::Scene {
public:
    void update(eng::Engine &engine) override {}

    void draw(eng::Engine &engine, term::Transform transform, term::Size size,
              term::TermScreen &screen) override {
        using namespace fmt;

        const auto percent = [&](double v) {
            return (v / engine.get_max_frame_time()) * 100;
        };

        screen.print(transform.move(size.getx() - 30, 0),
                     "{:05d}/{:05d}us ({:0.2f}%)", engine.get_frame_time(),
                     engine.get_max_frame_time(),
                     percent(engine.get_frame_time()));
    }

    static std::shared_ptr<PerfScene> make() {
        return std::make_shared<PerfScene>();
    }

private:
};
} // namespace uppr::app
