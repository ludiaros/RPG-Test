#include "WindowManager.hpp"

WindowManager::WindowManager():
    rotationRef(false),
    showInfo(true),
    showFPS(true),
    showLimits(false),
    fullscr(false),
    zoom(1),
    zoomMin(0.75),
    zoomMax(50),
    title("SF.SpaceG"),
    limits(sf::LinesStrip, 5)
{
    actionBindings["LCLICK"] = "VK_LBUTTON";
    actionBindings["ACCEPT"] = "VK_RETURN";
    actionBindings["CANCEL"] = "VK_ESCAPE";
    actionBindings["UP"]     = "VK_UP";
    actionBindings["DOWN"]   = "VK_DOWN";
    actionBindings["LEFT"]   = "VK_LEFT";
    actionBindings["RIGHT"]  = "VK_RIGHT";

    limits[0].position = sf::Vector2f(0, MAP_H);
    limits[0].color = sf::Color(0, 255, 0, 255);
    limits[1].position = sf::Vector2f(0, 0);
    limits[1].color = sf::Color(0, 255, 0, 255);
    limits[2].position = sf::Vector2f(MAP_W, 0);
    limits[2].color = sf::Color(0, 255, 0, 255);
    limits[3].position = sf::Vector2f(MAP_W, MAP_H);
    limits[3].color = sf::Color(0, 255, 0, 255);
    limits[4].position = sf::Vector2f(0, MAP_H);
    limits[4].color = sf::Color(0, 255, 0, 255);

    video.bitsPerPixel = video.getDesktopMode().bitsPerPixel;
    video.width = SCR_W;
    video.height = SCR_H;

    style = sf::Style::Default;

    view.reset(sf::FloatRect(0, 0, video.width, video.height));

    setKeyRepeatEnabled(false);
    setMouseCursorVisible(false);

    create(video, title, style);

    setFramerateLimit(FPS);
}

void WindowManager::setDefaultView() {

    setView(getDefaultView());
}

void WindowManager::restartClock() {

    frameTime = clockFPS.restart().asMilliseconds();
}

void WindowManager::toggleFullScreen() {

    if (fullscr) {

        video.width = video.getDesktopMode().width;
        video.height = video.getDesktopMode().height;
        style = sf::Style::Fullscreen;
    }
    else {

        video.width = SCR_W;
        video.height = SCR_H;
        style = sf::Style::Default;
    }

    setMouseCursorVisible(false);
    setKeyRepeatEnabled(false);

    create(video, title, style);

    setFramerateLimit(FPS);

    fullscr = !fullscr;
}

void WindowManager::resetZoom() {

    view.zoom(1 / zoom);
    zoom = 1;
}

void WindowManager::resetView() {

    setView(view);
}

void WindowManager::setZoom(float z) {

    if (zoom >= zoomMin && zoom <= zoomMax) {
        zoom *= z;
        view.zoom(z);
    }

    if (zoom <= zoomMin) {
        z = zoomMin / zoom;
        zoom = zoomMin;
        view.zoom(z);
    }

    if (zoom >= zoomMax) {
        z = zoomMax / zoom;
        zoom = zoomMax;
        view.zoom(z);
    }
}

void WindowManager::setCenter(sf::Vector2f center) {

    px = center.x;
    py = center.y;

    view.setCenter(center);
}

void WindowManager::drawLimits() {

    if (showLimits) {
        draw(limits);
    }
}

void WindowManager::drawFPS() {

    if (showFPS) {

        convert.str("");
        convert.clear();
        if (frameTime > 0) {
            convert << static_cast<int>(1000 / frameTime);
        }
        else {
             convert << 0;
        }
        fps = convert.str();

        drawText("FPS: " + fps, "mono", 16, TL, sf::Text::Regular, 10, 10, sf::Color::White);
    }
}

void WindowManager::drawText(
    sf::String txt,
    sf::String fontId,
    int fontSize,
    int align,
    int style,
    int x,
    int y,
    sf::Color color
) {

    font = *ResourceManager::getFont(fontId);
    text = sf::Text(txt, font, fontSize);
    text.setStyle(style);
    bounds = text.getLocalBounds();

    switch (align) {
        case TL: text.setOrigin(0,              0);               break;
        case TC: text.setOrigin(bounds.width/2, 0);               break;
        case TR: text.setOrigin(bounds.width,   0);               break;
        case ML: text.setOrigin(0,              bounds.height/2); break;
        case MC: text.setOrigin(bounds.width/2, bounds.height/2); break;
        case MR: text.setOrigin(bounds.width,   bounds.height/2); break;
        case BL: text.setOrigin(0,              bounds.height);   break;
        case BC: text.setOrigin(bounds.width/2, bounds.height);   break;
        case BR: text.setOrigin(bounds.width,   bounds.height);   break;
    }

    text.setPosition(x, y);
    text.setColor(color);
    draw(text);
}

bool WindowManager::getActionEvent(sf::String action) {

    if (eventMap[actionBindings[action]] == true) {

        eventMap[actionBindings[action]] = false;
        return true;
    }
    return false;
}

void WindowManager::handleWindowEvents(unsigned int& status) {

    sf::Event event;

    while (pollEvent(event)) {

        if (event.type == sf::Event::Closed) {

            close();
        }

        if (event.type == sf::Event::MouseWheelMoved) {

            if (status == PLAY) {

                setZoom(1 - (float) event.mouseWheel.delta / 5);
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {

            switch (event.mouseButton.button) {

                case sf::Mouse::Left:
                    eventMap["VK_LBUTTON"] = true;
                break;
            }
        }

        if (event.type == sf::Event::KeyReleased) {

            switch (event.key.code) {

                case sf::Keyboard::Add:
                    setZoom(0.95);
                break;

                case sf::Keyboard::Subtract:
                    setZoom(1.05);
                break;

                case sf::Keyboard::F4:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {
                        close();
                    }
                break;

                case sf::Keyboard::F11:
                    toggleFullScreen();
                break;

                case sf::Keyboard::Numpad0:
                    resetZoom();
                break;

                case sf::Keyboard::Escape:
                    eventMap["VK_ESCAPE"] = true;
                break;

                case sf::Keyboard::I:
                    showInfo = !showInfo;
                break;

                case sf::Keyboard::F:
                    showFPS = !showFPS;
                break;

                case sf::Keyboard::L:
                    showLimits = !showLimits;
                break;

                case sf::Keyboard::R:
                    if (status == PLAY) {
                        rotationRef = !rotationRef;
                    }
                break;

                case sf::Keyboard::Y:
                    eventMap["VK_Y"] = true;
                break;

                case sf::Keyboard::N:
                    eventMap["VK_N"] = true;
                break;

                case sf::Keyboard::Up:
                    eventMap["VK_UP"] = true;
                break;

                case sf::Keyboard::Down:
                    eventMap["VK_DOWN"] = true;
                break;

                case sf::Keyboard::Left:
                    eventMap["VK_LEFT"] = true;
                break;

                case sf::Keyboard::Right:
                    eventMap["VK_RIGHT"] = true;
                break;

                case sf::Keyboard::Return:
                    eventMap["VK_RETURN"] = true;
                break;

                default:
                    //Nothing to do here
                break;
            }
        }
    }
}
